#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int mob_no;
} pass_cc;

typedef struct
{
    char name[100];
    int mob_no;
    char food;
} pass_ec;

typedef struct cc
{
    int coach_num;
    pass_cc passengers[2][5];
    int vacant_seats;
    struct cc *next_cc;
    struct ec *next_ec;
} cc;

typedef struct ec
{
    int coach_num;
    pass_ec passengers[5];
    int vacant_seats;
    struct cc *next_cc;
    struct ec *next_ec;
} ec;

typedef struct
{
    char name[100];
    int regno;
    int cc_no;
    int ec_no;
    struct cc *next_cc;
    struct ec *next_ec;
} engine;

cc *initialise_cc(int num)
{
    cc *temp = (cc *)malloc(sizeof(cc));
    temp->vacant_seats = 10;
    temp->coach_num = num;
    temp->next_cc = NULL;
    temp->next_ec = NULL;
    return temp;
}

ec *initialise_ec(int num)
{
    ec *temp = (ec *)malloc(sizeof(ec));
    temp->vacant_seats = 5;
    temp->coach_num = num;
    temp->next_cc = NULL;
    temp->next_ec = NULL;
    return temp;
}

void insert_passenger_ec(pass_ec *pass)
{
    printf("Enter name, phone and food pref(V/N)\n");
    scanf(" %s", pass->name);
    // printf("Enter phone\n");
    scanf("%d", &pass->mob_no);
    // printf("Enter food\n");
    scanf(" %c", &pass->food);
}

void insert_passenger_cc(pass_cc *pass)
{
    printf("Enter name, phone\n");
    scanf(" %s", pass->name);
    scanf("%d", &pass->mob_no);
}

int insert_ec(engine *header)
{
    ec *temp = header->next_ec;
    while (temp->vacant_seats == 0)
    {
        if (temp->coach_num == 2)
            return -1;
        else
            temp = temp->next_ec;
    }
    insert_passenger_ec(&temp->passengers[5 - temp->vacant_seats]);
    printf("%s", temp->passengers[5 - temp->vacant_seats].name);
    temp->vacant_seats--;
    return 0;
}
int insert_cc(engine *header)
{
    cc *temp = header->next_cc;
    while (temp->vacant_seats == 0)
    {
        if (temp->coach_num == 3)
            return -1;
        else
            temp = temp->next_cc;
    }
    int filled_seats = 10 - temp->vacant_seats;
    insert_passenger_cc(&temp->passengers[filled_seats / 5][filled_seats % 5]);
    temp->vacant_seats--;
    return 0;
}

engine *initialise_train()
{
    engine *header = (engine *)malloc(sizeof(engine));
    strcpy(header->name, "Isha Sthanpati");
    header->regno = 200905258;
    header->cc_no = 3;
    header->ec_no = 2;
    header->next_cc = initialise_cc(1);
    header->next_cc->next_cc = initialise_cc(2);
    header->next_cc->next_cc->next_cc = initialise_cc(3);
    header->next_cc->next_cc->next_cc->next_ec = header->next_ec = initialise_ec(1);
    header->next_ec->next_ec = initialise_ec(2);
    return header;
}

void detach_empty(engine *header)
{
    cc *temp_cc = header->next_cc;
    cc *prev = NULL;
    if (header->next_cc->vacant_seats == 10)
    {
        header->next_cc = NULL;
        header->cc_no = 0;
    }
    else
    {
        while (temp_cc != NULL && temp_cc->vacant_seats != 10)
        {
            prev = temp_cc;
            temp_cc = temp_cc->next_cc;
        }
        if (temp_cc && temp_cc->vacant_seats == 10)
        {
            prev->next_cc = NULL;
            free(temp_cc);
            header->cc_no = prev->coach_num;
        }
    }
    ec *temp_ec = header->next_ec;
    ec *prev_ec = NULL;
    if (header->next_ec->vacant_seats == 5)
    {
        header->next_ec = NULL;
        header->ec_no = 0;
    }
    else
    {
        while (temp_ec && temp_ec->vacant_seats != 5)
        {
            prev_ec = temp_ec;
            temp_ec = temp_ec->next_ec;
        }
        if (temp_ec && temp_ec->vacant_seats == 5)
        {
            prev_ec->next_ec = NULL;
            free(temp_ec);
            header->ec_no = prev_ec->coach_num;
        }
    }
}

void print(engine *header)
{
    int coach_number_cc = 1;
    int coach_number_ec = 1;
    if (!header->next_cc && !header->next_ec)
    {
        printf("Cannot print empty!\n");
    };
    if (header->next_cc)
    {
        cc *temp = header->next_cc;
        cc *parent = NULL;
        while (temp)
        {

            printf("CC Coach number : %i", coach_number_cc);
            int i, j;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    if (i + j == 10 - temp->vacant_seats)
                        break;
                    printf("Coach type : CC\n");
                    printf("Name is %s\n", temp->passengers[i][j].name);
                    printf("Mobile number is %i\n", temp->passengers[i][j].mob_no);
                }
            }
            parent = temp;
            temp = temp->next_cc;
            coach_number_cc++;
        }
        ec *temp1 = parent->next_ec;
        while (temp1)
        {
            printf("EC Coach number : %i\n", coach_number_ec);
            int i, j;
            printf("%d", temp1->vacant_seats);

            for (i = 0; i < 5; i++)
            {

                if (i == 5 - temp1->vacant_seats)
                    break;
                printf("Coach type : EC\n");
                printf("Name is %s\n", temp1->passengers[i].name);
                printf("Mobile number is %i\n", temp1->passengers[i].mob_no);
                printf("Food type is : %c\n", temp1->passengers[i].food);
            }

            temp1 = temp1->next_ec;
            coach_number_ec++;
        }
    }
    else
    {
        ec *temp1 = header->next_ec;

        while (temp1)
        {
            printf("EC Coach number : %i\n", coach_number_ec);
            int i, j;
            printf("%d", temp1->vacant_seats);
            for (i = 0; i < 5; i++)
            {

                if (i == 5 - temp1->vacant_seats)
                    break;

                printf("Name is %s\n", temp1->passengers[i].name);
                printf("Mobile number is %i\n", temp1->passengers[i].mob_no);
                printf("Food type is : %c\n", temp1->passengers[i].food);
            }

            temp1 = temp1->next_ec;
            coach_number_ec++;
        }
    }
}

int main()
{
    engine *header = initialise_train();
    int ch = 0;
    while (ch != 4)
    {
        printf("1. Booking, 2. Departure, 3. Charting 4. Exit\nEnter Option\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("1. Executive Chair Car, 2. Chair Car\n Enter choice\n");
            int eng_no;
            scanf("%d", &eng_no);
            int pr;
            if (eng_no == 1)
                pr = insert_ec(header);
            else
                pr = insert_cc(header);
            if (pr == -1)
                printf("The coach is full\n");
            break;
        case 2:
            detach_empty(header);
            printf("Train departed with %d cc coaches and %d ec coaches\n", header->cc_no, header->ec_no);
            break;
        case 3:
            print(header);
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    }

    return 0;
}