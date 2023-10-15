#include <stdio.h>

void printSales(const float *data){
    printf("\nSales Summary\n\n");
    printf("%-10s%s","Month","Sales\n");
    const char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    for (int i=0;i <12; i++)
    {
        printf("%-10s%s%.2f\n", months[i], "$",data[i]);
    }
}
void minimum(const float *data){
    const char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    float min = data[1];
    int index = 0;
    for(int i=0;i<12;i++){
        if(data[i] < min){
            min = data[i];
            index = i;
        }
    }
    printf("\n%-10s%s%-10.2f%s\n","Minimum Sales: ","$",min,months[index]);
}

void maximum(const float *data){
    const char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    float max = data[1];
    int index = 0;
    for(int i=0;i<12;i++){
        if(data[i] > max){
            max = data[i];
            index = i;
        }
    }
    printf("\n%-10s%s%-10.2f%s\n","Maximum Sales: ","$",max,months[index]);
}

void average(const float *data){
    float average = 0.0;
    for(int i=0;i<12;i++){
        average += data[i];
        }
    average = average/12;
    printf("\n%-10s%s%-10.2f\n","Average Sales: ","$",average);
    }

void rollingAverage(const float *data){
    float mean;
    const char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    printf("\n6 Months Rolling Average\n");
    for(int i = 0; i < 7;i++){
        mean = 0;
        for(int j = i; j < i+6; j++){
            mean += data[j];
        }
        mean = mean/6;
        printf("%-10s%-5s%-10s%s%.2f\n",months[i],"-",months[i+5],"$",mean);
    }

}

void highestLowest(float *data){
    char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    for(int i =0; i <12; i++){
        for(int j = 0; j <11; j++){
            if(data[j] < data[j+1]){
                float temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
                char *tempMonth = months[j];
                months[j] = months[j+1];
                months[j+1] = tempMonth;


            }
        }
    }
     printf("\nSales Report - Highest to Lowest\n\n");
     printf("%-10s%s","Month","Sales\n");
    for (int i=0;i <12; i++)
    {
        printf("%-10s%s%.2f\n", months[i], "$",data[i]);
    }
    
}
int main() {
    float data[12]; 
    FILE *file;
    int line = 0;
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    for (line = 0; line < 12; line++)
     {
        fscanf(file, "%f", &data[line]);
    }
    fclose(file);
    printSales(data);
    minimum(data);
    maximum(data);
    average(data);
    rollingAverage(data);
    highestLowest(data);
    return 0;
}



