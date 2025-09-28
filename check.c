// // task is to take credit card number from user
// // and in output we have to show them which card they have
// // we have to check three cards( Visa, Mastercard , AmericanExpress )

#include <stdio.h>

int main()
{
    long long card_number = 4003600000000014;
    long long permenent_number = card_number;
    long long temp = 0;

    // remove last digit (start from second-last)
    card_number = card_number / 10;

    // Step 1: extract digits and build reversed number

    // now we will show how the upcoming while loop is going to work

    //  1) remove last digit for ex - 3
    //   2) crete a variable to store an all digits value
    //  3) now if digit = 4
    //  4) temp = temp * 10 + digit
    //  5) so here it will be temp = 0 * 10 + 4
    //  6) so now temp value is 4
    //  7) and this will work so like this temp = 4 ,  then temp = 43 then temp = 436 and so on
    while (card_number > 0)
    {
        int digit = card_number % 10; // card_number is not changing here !!!!!
        //  dont get confused here card_number is same at this point !
        temp = temp * 10 + digit;
        // printf("%d\n",temp);
        card_number = card_number / 100; // skip one digit
        // now here the card_number is changing to skip one digit
        // here we want to skip two digits that wise we divide it by "100"
        // if we divide that by "10" then all the way it will print all the numbers
    }
    // printf("%d\n", temp);
    // Step 2: print original digits
    long long copy = temp; // here we created one variable to store the value of temp
    long long reversed = 0;
    printf("%d\n", copy);
    while (copy > 0)
    {
        int d = copy % 10; // AGAIN TELLING YOU THAT COPY VALUE IS NOT CHANGING HERE !!!!! JUST LIKE AN CARD_NUMBER ABOVE
        // COPY VALUE WILL BE SAME "4366"
        // COPY VALUE WILL BE CHANGED AFTER WE WILL DIVIDE IT BY 10 COPY = COPY / 10
        // THEN ONLY AFTER THE VALUE OF COPY WILL BE CHANGED
        // SO AFTER WE DIVIDED IT BY 10 THEN THA VALUE OF COPY WILL BECOME "436" AND THEN "43" AND THEN "43"
        // SO BEFORE THIS LOOP STARTED THE VALUE OF COPY WAS COPY = 4366
        // AND AFTER THIS LOOP GET OVER THE VALUE OF COPY WAS COPY = 0

        reversed = reversed * 10 + d;
        // printf("%d\n", d);

        copy = copy / 10;
    }
    // printf("%lld\n", reversed);
    printf("\n");

    // step 3 :-

    int sum = 0;
    while (reversed > 0)
    {
        int multiple = reversed % 10;
        multiple = multiple * 2;
        if (multiple < 10)
        {
            // printf("%d\t",multiple);
            sum = sum + multiple;
        }
        // printf("%d",sum);
        if (multiple > 10)
        {
            multiple = (multiple / 10) + (multiple % 10);
            // printf("%d\t",multiple);
            sum += multiple;
            //   printf("%d\t %d\t",multiple/10,multiple%10);
        }
        reversed = reversed / 10;
    }
    // printf("sum = %d\t",sum);

    // card_number = 4003600000000014;
    while (permenent_number > 0)
    {
        int digit = permenent_number % 10;
        sum += digit;
        permenent_number = permenent_number / 100;
    }

    // printf("%d\n", sum);

    // card_number = 4003600000000014;
    if (permenent_number>= 4000000000000000 && permenent_number <= 4999999999999999)
    {
        if (sum % 10 == 0)
        {
                printf("valid card number\n");
                printf("VISA");   
        }
        else
        {
            printf("Invalid");
        }
    }
    // card_number = 4212888888881881;
}

