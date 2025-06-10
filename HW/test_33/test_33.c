#include <stdio.h>
#include <string.h>

#define GATEVALUE(Gate) int (*GateValue)(struct _Gate*)

typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;

int mask3bit(int value) {
    return value & 0x7;
}

int GateNOTValue(Gate* gate) {
    return mask3bit(~gate->input1);
}

int GateBUFFERValue(Gate* gate) {
    return mask3bit(gate->input1);
}

int GateANDValue(Gate* gate) {
    return mask3bit(gate->input1 & gate->input2);
}

int GateORValue(Gate* gate) {
    return mask3bit(gate->input1 | gate->input2);
}

int GateNANDValue(Gate* gate) {
    return mask3bit(~(gate->input1 & gate->input2));
}

int GateNORValue(Gate* gate) {
    return mask3bit(~(gate->input1 | gate->input2));
}

void CreateGate(Gate* obj, char* type, int input1, int input2) {
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

// 正確印出 3-bit binary（例如 2 -> 010）
void print_binary3(int value) {
    printf("%d%d%d\n", (value >> 2) & 1, (value >> 1) & 1, value & 1);
}

int main() {
    int x1, x2, x3;
    char types[5][3];

    scanf("%d %d %d", &x1, &x2, &x3);
    for (int i = 0; i < 5; i++) {
        scanf("%s", types[i]);
    }

    Gate Gx1, Gx2, Gx3, Gy, Gout;

    CreateGate(&Gx1, types[0], x1, 0);
    CreateGate(&Gx2, types[1], x2, 0);
    CreateGate(&Gx3, types[2], x3, 0);

    int out1 = Gx1.GateValue(&Gx1);
    int out2 = Gx2.GateValue(&Gx2);
    int out3 = Gx3.GateValue(&Gx3);

    CreateGate(&Gy, types[3], out1, out2);
    int y = Gy.GateValue(&Gy);

    CreateGate(&Gout, types[4], y, out3);
    int output = Gout.GateValue(&Gout);

    print_binary3(output);
    return 0;
}
