// File: hydro.h
// Exercise B
// Matthew Ho (30052684)
// Lab Section: B01 
// Date submitted:11/26/2020

int readData(FlowList& flow_list);

void displayHeader();

void Display(FlowList& flow_list);

void addData(FlowList& flow_list, int years, double flows);

void removeData(FlowList& flow_list, int year);

int average(FlowList& flow_list);

void saveData(FlowList &flow_list);

void pressEnter();

int menu();
