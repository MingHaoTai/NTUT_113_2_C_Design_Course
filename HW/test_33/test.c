#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define GATEVALUE(Gate) int(*GateValue)(struct _Gate*)

typedef struct _Gate{
    int input1;
    int input2;
    GATEVALUE(Gate);
}Gate;

int mask3bit(int value){
    return value & 0x7;
}

int GateNOTValue(Gate *gate){
    return mask3bit(~gate->input1);
}
int GateBUFFERValue(Gate *gate){
    return mask3bit(gate->input1);
}
int GateANDValue(Gate *gate){
    return mask3bit(gate->input1 & gate->input2);
}
int GateORValue(Gate *gate){
    return mask3bit(gate->input1 | gate->input2);
}
int GateNANDValue(Gate *gate){
    return mask3bit(~(gate->input1 & gate->input2));
}
int GateNORValue(Gate *gate){
    return mask3bit(~(gate->input1 | gate->input2));
}
void CreateGate(Gate *obj, char *type, int input1, int input2){
    obj->input1 = input1;
    obj->input2 = input2;

    if (strcmp(type, "N") == 0) 
        obj->GateValue = GateNOTValue;
    else if (strcmp(type, "B") == 0)
        obj->GateValue = GateBUFFERValue;
    else if (strcmp(type, "A") == 0)
        obj->GateValue = GateANDValue;
    else if (strcmp(type, "O") == 0)
        obj->GateValue = GateORValue;
    else if (strcmp(type, "NA") == 0)
        obj->GateValue = GateNANDValue;
    else if (strcmp(type, "NO") == 0)
        obj->GateValue = GateNORValue;
}

int main(){
    int a, b, c;
    char type[5][3];
    scanf("%d %d %d", &a, &b, &c);
    scanf("%s %s %s %s %s", type[0], type[1], type[2], type[3], type[4]);
    Gate gate_a, gate_b, gate_c, gate_y, gate_o;

    CreateGate(&gate_a, type[0], a, 0);
    CreateGate(&gate_b, type[1], b, 0);
    CreateGate(&gate_c, type[2], c, 0);
    
    int out1 = gate_a.GateValue(&gate_a);
    int out2 = gate_b.GateValue(&gate_b);
    int out3 = gate_c.GateValue(&gate_c);

    CreateGate(&gate_y, type[3], out1, out2);
    int y = gate_y.GateValue(&gate_y);

    CreateGate(&gate_o, type[4], y, out3);
    int output = gate_o.GateValue(&gate_o);
    printf("%d%d%d\n", (output >> 2) & 1, (output >> 1) & 1, output & 1);
    return 0;
}