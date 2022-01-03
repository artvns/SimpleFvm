#ifndef SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_ABSTRACTCOEFFSCALCULATOR_H
#define SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_ABSTRACTCOEFFSCALCULATOR_H

#include <cstddef>
#include <string>
#include <memory>

#include "FVMSolver/Tools/LocalAdt/MapAdt.cpp"
#include "FVMSolver/Tools/Enums/EnumAdjacentCellTypes.cpp"
#include "FVMSolver/CoeffsPartsCommon/CellNumbers/CellNumbers.h"
#include "FVMSolver/CoeffsPartsCommon/CellTypes/CellTypes.h"
#include "FVMSolver/CoeffsPartsCommon/DataExchanger/AbstractDataExchanger.h"


namespace fvmsolver {

class AbstractCoeffsCalculator {
protected:
    using uPtrAbstractDataExchanger = std::unique_ptr<AbstractDataExchanger>;
    using uPtrCellNumbers = std::unique_ptr<CellNumbers>;
    using uPtrCellTypes = std::unique_ptr<CellTypes>;
    
    using shPtrMapCellNumbers = std::shared_ptr<MapAdt<uPtrCellNumbers>>;
    using shPtrMapCellTypes = std::shared_ptr<MapAdt<uPtrCellTypes>>;
    using shPtrMapAbstractDataExchanger = std::shared_ptr<MapAdt<uPtrAbstractDataExchanger>>;

public:
    AbstractCoeffsCalculator();
    virtual ~AbstractCoeffsCalculator() = 0;

    virtual void chooseActualDomainPart(std::string partName);

    void addCellNumsSet(shPtrMapCellNumbers spCellNumsSet);
    void addCellTypesSet(shPtrMapCellTypes spCellTypesSet);
    void addDataExchangerSet(shPtrMapAbstractDataExchanger spDataExchangerSet);

    void calculateInterior(size_t id);
    void calculateBoundary(size_t id);

    double getAp();
    double getAw();
    double getAe();
    double getAn();
    double getAs();
    double getRHS();
    double get_b();

    size_t get_pNum();
    size_t get_wNum();
    size_t get_eNum();
    size_t get_nNum();
    size_t get_sNum();

    bool is_wInterior();
    bool is_eInterior();
    bool is_nInterior();
    bool is_sInterior();

protected:
    CellNumbers* pCellNums_ = nullptr;
    CellTypes* pCellTypes_ = nullptr;
    AbstractDataExchanger* pDataExchanger_ = nullptr;

    shPtrMapCellNumbers pCellNumsSet_ = nullptr;
    shPtrMapCellTypes pCellTypesSet_ = nullptr;
    shPtrMapAbstractDataExchanger pDataExchangerSet_ = nullptr;

    size_t id_ = 0;
    size_t bcId_ = 0;
    double a_p_ = 0.0;
    double a_w_ = 0.0;
    double a_e_ = 0.0;
    double a_n_ = 0.0;
    double a_s_ = 0.0;
    double rhs_ = 0.0;
    double b_ = 0.0;

    size_t pNum_ = 0;
    size_t wNum_ = 0;
    size_t eNum_ = 0;
    size_t nNum_ = 0;
    size_t sNum_ = 0;

    EnumAdjacentCellTypes wType_ = EnumAdjacentCellTypes::ADJACENT_CELL_INTERIOR;
    EnumAdjacentCellTypes eType_ = EnumAdjacentCellTypes::ADJACENT_CELL_INTERIOR;
    EnumAdjacentCellTypes nType_ = EnumAdjacentCellTypes::ADJACENT_CELL_INTERIOR;
    EnumAdjacentCellTypes sType_ = EnumAdjacentCellTypes::ADJACENT_CELL_INTERIOR;

    double dw_ = 0.0;
    double de_ = 0.0;
    double dn_ = 0.0;
    double ds_ = 0.0;

    virtual void calculateCoeffsWENS(size_t id) = 0;
    virtual void calculateCoeffP() = 0;
    virtual void calculateRHS(size_t id) = 0;

    virtual void begin(size_t id) {};
    virtual void end(size_t id) {};
    virtual void calculateAdditional(size_t id) {};
    virtual void calculateSource(size_t id) {};
    virtual void setCoeffsToZero() {};

    bool isInteriorType(const EnumAdjacentCellTypes& type);
    void chooseCommonComponents(std::string partName);

private:

};

}
#endif // SIMPLEFVM_FVMSOLVER_COEFFSCALCULATORS_CALCULATORS_ABSTRACTCOEFFSCALCULATOR_H