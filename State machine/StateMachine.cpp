#include <stdio.h>

class state{
    public:
    virtual void inputGraterZero() = 0;
    virtual void inputLessZero()   = 0;    
    virtual void stateAction()     = 0;
};
class  machine{
    private:
    state *currentState;
    state *possibleStates[2];
    public:
    machine(state *initState , state *stateOne , state *statetwo){
        currentState = initState;
        possibleStates[0] = stateOne;
        possibleStates[1] = statetwo;
    }
    void machineInput(float x){
        if (x>0){
            currentState->inputGraterZero();    
        }
        else if(x<0){
            currentState->inputLessZero();
        }
    }
    void setSate(int index){
        currentState = possibleStates[index];
    }
    void machineAct(){
        currentState->stateAction();
    }
};

class GenralState {
    protected:
        int Id;
        machine *System;
    public:
        GenralState(int stateId){
            Id = stateId;            
        }
        void setSystem(machine *system){
            System = system;
        }        
};

class stateOne: public GenralState, public state{
    public:
        stateOne(int id): GenralState(id){}
        void inputGraterZero(){
            System->setSate(1);
        }
        void inputLessZero(){
            System->setSate(0);
        }
        void stateAction(){
            printf("the state ID is %d \n",Id);
        }    
};

class statetwo: public GenralState, public state{
    public:
        statetwo(int id): GenralState(id){}
        void inputGraterZero(){
            System->setSate(1);
        }
        void inputLessZero(){
            System->setSate(0);
        }
        void stateAction(){
            printf("the state ID is %d \n",Id);
        }    
};

int main(void){
    stateOne S1(1);
    statetwo S2(2);
    machine System_example(&S1, &S1, &S2);
    S1.setSystem(&System_example);
    S2.setSystem(&System_example);


    System_example.machineInput(4);
    System_example.machineAct();
    System_example.machineInput(-3);
    System_example.machineAct();
}