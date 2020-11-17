#include <stdio.h>


class StateImplementation{
    public:
        virtual void stateAct(int id) = 0;
};
class Machine{
    public:
        virtual void machineInput(float x) = 0;
        virtual void setSate(int index) = 0;
        virtual void machineAct() = 0;     
};

class stateTransition{
    public:
        virtual void inputGraterZero(Machine *system ) = 0;
        virtual void inputLessZero(Machine *system )   = 0;
};
class StateLogic:public StateImplementation{
    public:
        void stateAct(int id){
            printf("this state is %d \n",id);
        }
};

class StateLogicII:public StateImplementation{
    public:
        void stateAct(int id){
            printf("++++++++++++++++++++++++++\n");
            printf("the Id of this state is %d\n",id);
        }
};

class GenralState{
    protected:
        int Id;
        Machine *System;
        StateImplementation *stateAction;        
    public:
        stateTransition *Trans;
        GenralState(int stateId, StateImplementation *stateaction, stateTransition *tran){
            Id = stateId;
            stateAction = stateaction;
            Trans = tran;            ;
        }
        void setSystem(Machine *system){
            System = system;
        }
        void stateLogicFaire(){
            stateAction->stateAct(Id);
        }        
};

class  stateMachineTest: public Machine{
    private:
    GenralState *currentState;
    GenralState *possibleStates[2];
    public:
    stateMachineTest(GenralState *initState , GenralState *stateOne , GenralState *statetwo){
        currentState = initState;
        possibleStates[0] = stateOne;
        possibleStates[1] = statetwo;
    }
    void machineInput(float x){
        if (x>0){
            currentState->Trans->inputGraterZero(this);    
        }
        else if(x<0){
            currentState->Trans->inputLessZero(this);
        }
    }
    void setSate(int index){
        currentState = possibleStates[index];
    }
    void machineAct(){
        currentState->stateLogicFaire();
    }
};

class stateTranOne:public stateTransition{
    public:        
        void inputGraterZero(Machine *System){
            System->setSate(1);
        }
        void inputLessZero(Machine *System){
            System->setSate(0);
        }          
};

class stateTrantwo:public stateTransition{
    public:        
        void inputGraterZero(Machine *System){
            System->setSate(1);
        }
        void inputLessZero(Machine *System){
            System->setSate(0);
        }        
};

int main(void){
    StateLogic printLogic;
    StateLogicII printLogicII;
    stateTranOne T1;
    stateTrantwo T2;
    GenralState S1(1, &printLogic, &T1);
    GenralState S2(2, &printLogicII, &T2);
    stateMachineTest System_example(&S1, &S1, &S2);
    S1.setSystem(&System_example);
    S2.setSystem(&System_example);
    


    System_example.machineInput(4);
    System_example.machineAct();
    System_example.machineInput(-3);
    System_example.machineAct();
}