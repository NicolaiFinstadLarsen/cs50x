#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{

    // Sette igang innhenting av nummer, bevare original nummer \n
    // og starte count for å verifisere VISA, MASTER etc. \n
    // Pluss starte alle variablene. Er dette nødvendig?
    long num = get_long("Number: ");
    long num_org = num;
    long count = 0;
    long num_verif = 0;
    long add_even = 0;
    long mod2 = 0;
    long mod3 = 0;
    long add_odd = 0;
    long check_sum = 0;
    long count_full = 0;



    while (num > 0)
    {
        // Her skiller vi ut siste tallet og fjerner det.
        long mod = num % 10;

        //printf("Mod er: %li \n", mod);
        num = num / 10;

        // printf("Num er: %li \n", num);
        count++;

        // Jeg tar også vare på count her for å kunne bruke den i validering til slutt.
        count_full = count;

        //printf("Count er: %li \n", count);

        // Her plusser vi sammen tallene som skal ganges med 2
        // Det er tallene som starter fra nest siste plassering som skal ganges med 2.
        // Dette gjør jeg ved å se om count er partall.
        // det skal så plusses sammen
        if (count % 2 == 0)
        {

            mod2 = mod * 2;


            // Fordi det bare er enkelt tall som skal plusses sammen. \n
            // Må jeg sjekke at ingen tall er over 10 etter å gange med 2.
            // Er de det må de inn i en egen variabel som plusses inn etter while loopen.
            if (mod2 >= 10)
                {
                    mod3 = mod2 % 10;
                    mod2 = mod2 / 10;

                    // Her legger vi inn partallene som måtte splittes etter å gange med to.
                    add_even = add_even + mod3;
                    mod3 = 0;

                }

            // Her legger vi sammen partallene som er enkelt tall.
            add_even = add_even + mod2;

            //Dette er bare en haug med check prints
            //printf("Mod 2 er: %li \n", mod2);
            //printf("Mod 3 er: %li \n", mod3);
            //printf("Add even er: %li \n", add_even);
    }
        // Hvis count er oddetall skal det bare plusses sammen
        if (count % 2 == 1)
        {
            add_odd = add_odd + mod;
            printf("Odd er: %li \n", add_odd);
        }
    }


    // printf("Summen av hvert andre tall er: %li \n", add_even);
    // printf("Summen av de resterende tallene er: %li \n", add_odd);


    // Vi legger partall og oddetall sammen for å sjekke om kortnummeret er gyldig.
    check_sum = add_even + add_odd;
    //printf("Check_sum er: %li \n", check_sum);


    // Bare en runde for å kunne printe ut hva mod av check_sum er.
    long check_sum_check = check_sum % 10;
    //printf("Check_sum_check er: %li \n", check_sum_check);


    //Kortnummeret er gyldig hvis siste tallet i summen er 0.
    // Er det ikke 0 printer vi INVALID og exit script.
    if (check_sum % 10 > 0)
    {
        printf("INVALID\n");
        exit(0);
    }

    //printf("Count er: %li \n", count);



    num_verif = num_org;

    while (count > 2)
    {

        //printf("Num org er: %li \n", num_verif);

        // I denne delen skal vi finne ut hvilken leverandør som har utsendt kortet. \n
        // Vi gjør det ved å finne de to første tallene i tallrekken vi originalt fikk i input.
        long mod_verif = num_verif % 10;

        //printf("Mod verif er: %li \n", mod_verif);

        num_verif = num_verif / 10;
        count--;
        //printf("Count er: %li \n", count);
    }
    //printf("Num verif er: %li \n", num_verif);
    if ((num_verif == 40 || num_verif == 41 || num_verif == 42 || num_verif == 43 || num_verif == 44 || num_verif == 45 || num_verif == 46 || num_verif == 47 || num_verif == 48 || num_verif == 49) && (count_full == 13 || count_full == 16))
    {
        printf("VISA\n");
    }
    else if ((num_verif == 51 || num_verif == 52 || num_verif == 53 || num_verif == 54 || num_verif == 55) && count_full == 16)
    {
        printf("MASTERCARD\n");
    }
        else if ((num_verif == 34 || num_verif == 37) && count_full == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
