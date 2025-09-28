// task is to solve the problem of "change" in the minimum ways
// 25$ , 10$ , 5$ , 1$
// if change is required for 30$ then -> 25$ + 5$ = 2 coins are required

#include <stdio.h>
int main()
{
    int change;
    int total = 0;
    int quaters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennis = 1;
    int change_left;
    // printf("how many change is required ?");
    // scanf("%d", &change);
    // printf("%d is req.\n", change);

     do
     {
        printf("How many change is required ?");
        scanf("%d",&change);
     } while (change <= 0);
     
    do
    {
        while (change >= quaters)
        {
                change_left = change - quaters;
                // printf("left value is %d\n",change_left);
                change = change_left;
                // printf("change value after deduction is %d\n", change);
                total++;
        }
        // printf("now chanking the value of change_left  is %d and the value of change is %d\n",change_left, change);
        while(change >= dimes)
        {
            change_left = change - dimes;
            change = change_left;
            total++;
        }
        while(change >= nickels){
            change_left = change - nickels;
            change = change_left;
            total++;
        }
        while(change >= pennis){
            change_left = change - pennis;
            change = change_left;
            total++;
        }
    } while (change!= 0);

    // printf("total %d change is required for %d change", total, change);
    printf("%d",total);
}