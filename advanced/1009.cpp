#include <cstdio>

int main() {
    freopen("./sample_in/1009.txt", "r", stdin);
    double e1[1010] = {0.0}, e2[1010] = {0.0}, e3[2010] = {0.0}, temp2;
    int num, index = 0, temp1, e3Sum = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d%lf", &temp1, &temp2);
        e1[temp1] = temp2;
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d%lf", &temp1, &temp2);
        e2[temp1] = temp2;
    }
    for(int i = 0; i < 1010; i ++) {
        if(e1[i] != 0) {
            for(int j = 0; j < 1010; j++) {
                if(e2[j] != 0) {
                    e3[i + j] += e1[i] * e2[j];
                }
            }
        }        
    }
    for(int i = 0; i < 2010; i++) {
        if(e3[i] != 0) {
            e3Sum++;
        }
    }
    for(int i = 0; i < 2010; i++) {
        if(e3[i] != 0) {
            index = i;
            break;
        }
    }
    printf("%d ", e3Sum);
    for(int i = 2009; i >= 0; i--) {
        if(i == index) {
            break;
        }
        if(e3[i] != 0) {
            printf("%d %.1f ", i, e3[i]);
        }
    }
    printf("%d %.1f", index, e3[index]);

    return 0;
}