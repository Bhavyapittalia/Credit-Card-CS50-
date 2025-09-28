#include<stdio.h>

int checkCardInvalidation(int sum) {
    if (sum % 10 == 0) {
        return 1; //true
    }
    return 0; // false
}

int checkVisa(long long temporary_number) {
    if((temporary_number>=4000000000000000 && temporary_number<=4999999999999999)|| 
        (temporary_number>=4000000000000 && temporary_number <=4999999999999)){
        return 1;
    }
    return 0;
}

int checkMastercard(long long temporary_number){
        if(temporary_number>=5100000000000000 && temporary_number<= 5599999999999999) 
        {
            return 1;
        }
        return 0;
    }

int checkAmericanExpress(long long temporary_number){
         if((temporary_number>=340000000000000  && temporary_number<=349999999999999) || 
        (temporary_number>=370000000000000  && temporary_number<=379999999999999)){
            return 1;
        }
        return 0;
    }



int main(){
    long long card_number=4111111111111114;// 5199999999999991    4222222222223
    // printf("Number: ");
    // scanf("%lld",&card_number);
    long long correct_number = card_number;
    long long temporary_number = card_number;
    int sum = 0; 

    card_number = card_number / 10;

    // this loop is for printing numbers from second-last digit  
    while(card_number>0){
        int digit = card_number % 10;
        card_number = card_number / 100 ;
        // printf("%d\t",digit*2);
        int doubled = digit*2;
        if(doubled < 10){
            sum+=doubled;
        }
        if(doubled >=10){
            sum+=(doubled % 10) + (doubled / 10);
        }
    }

    // and this loop is for printing numbers which we have not printed in first loop
      while(correct_number > 0 ) {
        int not_selected = correct_number % 10;
        sum+=not_selected;
        correct_number = correct_number / 100;
    }   

    if (!checkCardInvalidation(sum)) {
        printf("INVALID");
        return 0;  // WE ARE WRITING "return = 0" bcz to exit our programme smoothly without running any out futher code unnessecerily
    }

    if (checkVisa(temporary_number)) {
        printf("VALID\n");
        printf("VISA");
        return 0;
    }

    if(checkAmericanExpress(temporary_number)){
        printf("VALID\n");
        printf("AMERICAN-EXPRESS");
        return 0;
    }

    if(checkMastercard(temporary_number)){
        printf("VALID\n");
        printf("MASTER-CARD");
        return 0;
    }

    printf("INVALID"); // NOW THIS IS WORKING LIKE A ELSE CONDITION HERE 
    return 0;


    //  Difference between programme which I have wrote below (if-else if-else)and in function is that In (if-else if-else) programme every card will be check "unnesecarily" and In funtion programme only "needed" condition or a function will be executed   

    // if(sum % 10 == 0 ) {
    //     if((temporary_number>=4000000000000000 && temporary_number<=4999999999999999)|| 
    //        (temporary_number>=4000000000000 && temporary_number <=4999999999999)){
    //          printf("VALID\n");
    //          printf("VISA");
    //     }
    //     else if((temporary_number>=340000000000000  && temporary_number<=349999999999999) || 
    //     (temporary_number>=370000000000000  && temporary_number<=379999999999999)){
    //          printf("VALID\n");
    //          printf("AMERICAN-EXPRESS");
    //     }
    //     else if(temporary_number>=5100000000000000 && temporary_number<= 5599999999999999) 
    //     {
    //          printf("VALID\n");
    //          printf("MASTER-CARD");
    //     }
    //     else{
    //         printf("INVALID CARD NUMBER\n");
    //     }
    // }
    // else{
    //     printf("INVALID CARD NUMBER AS OF SUM RULE");
    // }

}