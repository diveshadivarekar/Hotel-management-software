#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


void begin();
void program();
void show_details();
void complaints_suggestions();
void book_room();
void mini_casino();
void GuessGame(int,int*);
void getInfo();

struct {
    char name[20];
    char address[50];
    char email_id[30];
    char nationality[25];
    int roomno;
    char *roomtype;
    int billprice;
    char *program;
}person;


//     0 = Black       8 = Gray
//     1 = Blue        9 = Light Blue
//     2 = Green       A = Light Green
//     3 = Aqua        B = Light Aqua
//     4 = Red         C = Light Red
//     5 = Purple      D = Light Purple
//     6 = Yellow      E = Light Yellow
//     7 = White       F = Bright White
// Example: "COLOR fc" produces light red on bright white





void main()
{
    system("COLOR fc");
    person.roomno =0;
    person.billprice =0;
    person.program = "notchosen";
    printf(".............WELCOME TO Divesh Industries PVT LTD..............\n");
    printf("***************************************************************\n");
    printf("Please enter your details before moving to the main page!\n\n");
    printf("\t\tForm\n");
    printf("please enter your name:");
    gets(person.name);
    printf("enter your address:");
    gets(person.address);
    printf("enter your nationality:");
    gets(person.nationality);
    printf("enter your email_id:");
    gets(person.email_id);
    system("cls");
    time_t timer = time(NULL);/*to get the present local time*/
    begin();
}

void begin()
{
    // system("cls");
    int decide;
    printf("\n-----------------------HOME PAGE--------------------------\n");
    printf("\n HOW CAN WE HELP YOU?\n\n");
    printf("\n1.Book a room\n2.Program\n3.mini casino\n4.show my details\n5.complaints or suggestions\n6.check out\n7.about us\n");
    scanf("%d",&decide);
    switch(decide)
    {
        case 1:
        book_room();
        break;
        case 2:
        program();
        break;
        case 3:
        mini_casino();
        break;
        case 4:
        show_details();
        break;
        case 5:
        complaints_suggestions();
        printf("Thank you for your valuable suggestions!\n");
        begin();
        break;
        case 6:
        printf("Visit again!\n");
        printf("Thank you for trusting our service.\n");
        break;
        case 7:
        printf("GHUMTEE RIVERA RESORT:\n");
        printf(" A beautiful cosmopolitan destination for a picturesque natural scenario, a blend of Natural and Artificial effort located on the border of");
        printf("Chitwan National park (A UNESCO World Heritage Site) allows you to enjoy the breeze of Rapti River flowing through the lap of Chitwan National Park.");
        printf("Enjoying the spectacular sunset and its reflection on Rapti River along with grazing of deer on the bank by relaxing on our rugged cottages");
        printf("is the memorable experience you could enjoy only at GHUMTEE RIVERA RESORT. \n");
        printf("We would be more than happy to experience you Jungle Safari, canoe ride to CrocodileBreeding Farm and Ox-Cart ride.");
        printf("Clean and Comfortable room, Hot and Cold Water facilities, beautiful garden, family environment, local food are our salient features to give you taste of our Nepalese Culture.");
        printf("Satisfying you totally with our unique culture is our primary motto.\n");
        begin();
        break;
        default:
        printf("invalid option");
    }
}

void program()
{
    // printf("program");
    system("cls");
    int p;
    printf("\nWhich program do you want to choose?\n");
    printf("\n 1.Jungle Walk \n 2.Jungle Jeep Drive\n 3.Canoe ride \n 4. Cultural show ");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
        system("cls");
        printf("\nYou choose jungle walk\n");
        person.program = "Jungle walk";
        person.billprice += 1000;
        begin();
        break;

        case 2:
        printf("\nYou choose jungle jeep drive\n");
        person.program = "Jeep Drive";
        person.billprice += 2000;
        begin();
        break ;

        case 3:
        printf("\nYou choose canoe ride\n");
        person.billprice+= 800;
        person.program = "Canoe Ride";
        begin();
        break;

        case 4:
        printf("\nYou choose cultural show\n");
        person.billprice+= 1000;
        person.program = "Cultural show";
        begin();
        break;

        default:
        begin();
    }
}

void show_details()
{
    // printf("show details");
    system("cls");
    time_t timer = time(NULL);
    printf("you can get your details in hotel.txt file\n");
    FILE *ifp;
    ifp = fopen("hotel.txt","w+");
    if(ifp == NULL){
        printf("file cant be opened\n");
    }
    else
    {
        fprintf(ifp,"........DETAILS......\n");
        fprintf(ifp,"Name : %s\n",person.name);
        fprintf(ifp,"Nationality : %s\n",person.nationality);
        fprintf(ifp,"Email id : %s\n",person.email_id);
        fprintf(ifp,"Address : %s\n",person.address);
        fprintf(ifp,"Arrival time: %s\n",ctime(&timer));
        fprintf(ifp,"Roomno : %d\n",person.roomno);
        fprintf(ifp,"Roomtype : %s\n",person.roomtype);
        if(strcmp(person.program,"notchosen") != 0)
        {
            fprintf(ifp,"Program : %s\n",person.program);
        }
        fprintf(ifp,"your bill price is %d\n",person.billprice);
        fprintf(ifp,"press p to print your details");
        fflush(ifp);
        fclose(ifp);
        getInfo();
        begin();
    }
}

void getInfo()
{
    // system("cls");
    // printf("you can get your details in hotel.txt file\n");
    char ch ;
    int count=1;
    FILE *ifp;
    ifp = fopen("hotel.txt","r");
    if(ifp == NULL)
    {
        puts("Unable to open the file ");
    }
    while((ch = getc(ifp)) !=EOF)
    {
        if(ch == '\n')
        {
            count++;
            printf("\n");
            // printf("\n%3d:",count);
        }
        else
        {
            printf("%c",ch);
        }
    }
    fclose(ifp);

}

void complaints_suggestions()
{
    // printf("complaint suggestion");
    system("cls");
    char complain[500];
    FILE *fpt;
    if(fpt == NULL)
    {
        printf("file cant be opened\n");
    }
    else
    {
        printf("please enter your complaints or suggestions\n");
        fflush(stdin);
        gets(complain);
        fpt = fopen("complain.txt","w+");
        fputs(complain,fpt);
        fclose(fpt);
    }
}

void book_room()
{
    // printf("book room");
    system("cls");
    if(person.roomno == 0)
    {
        int type_of_rooms;
        char ch,c;
        printf("\nWhat type of room do u want to book?\n");
        printf("\n1.Basic Room Rs 1000\n2.Medium room Rs 2000\n3.DELUXE ROOM Rs 3000\n4.I don't want to choose anything\n");
        scanf("%d",&type_of_rooms);
        fflush(stdin);
        if(type_of_rooms==1)
        {
            printf("\nDo you accept this room?(y/n)\n");
            fflush(stdin);
            scanf("%c",&c);
            if (c=='y')
            {
                system("cls");
                printf("\nYou choose basic room. Enjoy your stay\n");
                printf("your room no is 121");
                person.roomno = 121;
                person.roomtype = "basic";
                person.billprice += 1000;
                begin();
            }
            else
            begin();
        }
        if(type_of_rooms==2)
        {
            printf("\nDo you accept this room?(y/n)\n");
            scanf("%c",&c);
            if(c=='y')
            {
                system("cls");
                printf("\nYou choose medium room. Enjoy your stay\n");
                printf("your room no is 212");
                person.billprice += 2000;
                person.roomno = 212;
                person.roomtype = "medium";
                begin();
            }
            else
            begin();
        }
        if(type_of_rooms==3)
        {
            printf("\nDo u accept this room?(y/n)\n");
            scanf("%c",&c);
            if(c=='y')
            {
                system("cls");
                printf("\nYou choose deluxe room. Enjoy your stay\n");
                printf("your room no is 312");
                person.billprice += 3000;
                person.roomtype = "deluxe";
                person.roomno = 312;
                begin();
            }
            else
            begin();
        }
        if(type_of_rooms==4)
        {
            begin();
        }
    }
    else
    printf("you have already booked a room");
}

void mini_casino()
{
    // printf("mini casino");
    int amount_bet, inhand_cash;
    /*
    You have to guess the right number among 3 numbers.
    The position where right number is is
    named as 'R' and rest two are named as 'N'
    If your guess is wrong, you loose the
    amount_bet from your inhand_cash
    If you guess it right, you win
    twice the amount_bet in your inhand_cash
    Keep playing and keep winning
    until you go out of cash
    */
    printf("\n////////-WELCOME TO MINI CASINO-\\\\\\\\\\\\ \n");
    printf("\n----Enter the inhand_cash you have right now---- :\n ");
    scanf("%d", &inhand_cash);
    while (inhand_cash > 0)
    {
        printf("\nEnter the amount_bet you want to play for : \n");
        scanf("%d", &amount_bet);
        if (inhand_cash == 0 || amount_bet > inhand_cash)
        {
            break;
        }
        else if(amount_bet==100)
        {
            printf("very low amount to play with");
            continue;
        }
        else
        {
            GuessGame(amount_bet, &inhand_cash);
        }
    }
    if (inhand_cash == 0 || amount_bet > inhand_cash)
    {
        printf("\n\""" \nSorry you don't have enough cash to play more,\n ");
        printf("\nDo come next time\""
        "\n\n");
        printf("\nThank You for playing \n");
    }

}

void GuessGame(int amount_bet, int* inhand_cash)
{
    char num[3] = { 'N', 'R', 'N' };
    printf("\nWait !! number is shuffling its position...\n");
    srand((time(NULL)));
    int i, x, y, temp;
    /*Swapping the number's position five times using
    the random number for random index*/
    for (i = 0; i < 5; i++)
    {
        x = rand() % 3;
        y = rand() % 3;
        temp = num[x];
        num[x] = num[y];
        num[y] = temp;
    }
    int PlayerGuess;
    printf("\nYou may now guess the number in which R is present: ");
    scanf("%d", &PlayerGuess);
    if (num[PlayerGuess - 1] == 'R')
    {
        (*inhand_cash) += 2 * amount_bet;
        printf("You win ! The numbers are as follows: ");
        printf("\"%c %c %c\" ", num[0], num[1], num[2]);
        printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
    }
    else
    {
        (*inhand_cash) -= amount_bet;
        printf("You Loose ! The numbers are as follows: ");
        printf("\"%c %c %c\" ", num[0], num[1], num[2]);
        printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
    }
}


