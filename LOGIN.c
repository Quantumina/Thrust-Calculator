#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

struct login
{
    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
    char c[100];
};
void registe();
void login();
void invalid();

void registe()
{
   FILE *log;
   log = fopen("D:\\VS Progs\\login12.txt", "w");
   struct login l;
    int i=0;
    char c = ' ';
    printf("Enter First Name: ");
    scanf("%s", l.fname);
    printf("Enter Last Name: ");
    scanf("%s", l.lname);
    printf("Enter Username: ");
    scanf("%s", l.username);
    printf("Enter Password [max lenght 10]: ");
    
    while ((c=getch()) != 13)
    {
    if((c == 8))
    {
    putch('\b');
    putch(' ');
    putch('\b');
    i--;
    continue;
    }
    if(i<0)i = 0;
    l.password[i]= c;
    i++;
    putch('*');
    }
    l.password[i]='\0';
    
printf("\n");
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    printf("\n\nYour User name is UserId\n");
    printf("Now login with UserID and Password\n");
    printf("\nPress any key to continue.....\n");
    login();
}

void login()
{
    char username[200], password[20], c = ' ';
    int i=0;
    FILE *log;
    log = fopen("D:\\VS Progs\\login12.txt", "r");
    struct login l;
    printf("\nUserID: ");
    scanf("%s", username);


printf("Password : ");
while ((c=getch()) != 13)
    {
    if((c == 8))
    {
    if(i<0) i = 0;
    putch('\b');
    putch(' ');
    putch('\b');
    i--;
    continue;
    }
    if(i < 0) i = 0;
    password[i]= c;
    i++;
    putch('*');
    }
    password[i]='\0';
    
printf("\n");

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\n\nSuccessful login\n");
        }
        else
        {
        printf("\n\nInCorrect UserID or Password");
        exit(0);
        }
    }

    fclose(log);
}
*/
void main()
{  
    int decision=0;
    do
    {
    int choice;
    printf("\nPress '1' for Register \nPress '2' for Login\n--> ");
    scanf("%d", &choice);
    if(choice == 1)
    {
    
        registe();
        break;
    }
    else if(choice == 2)
    {
        
        login();
        break;
    }
    else if (choice != 1 || choice != 2)
    {
    printf("Error: Invalid Choice!");
    decision = 1;
    }
    }while(decision);
    
    FILE *fp, *kp, *sp, *mp, *ip;
    int flag =1;
    double Dc, Lc, Do, d, Lo, N, MCP, To, C, Patm, R, M, K, p, Knmax, Vc, Lgo, Vg, mg, Abmax, At, Ab, x, Kn, di,a,n,t,Po,v,s,m,b,i,j,r,Cf,F;
    To = 1710; 	 //Chamber temperature(K)
    C = 889;		 //Characteristics Exhaust Velocity(m/s)
    Patm = 101000;         //Ambeint pressure(Atmospheric Pressure)(Pa)
    R = 196.1;   	//spedific gas constant(J/mol-K)
    M = 42.39;	//Molar Weight(kg/Kmol)
    K = 1.131;	//Specific heat ratios
    p = 1.879;	//Density of grain(g/cm3)
    n = 0.319;	//Pressure Exponential
    a = 0.0665;	//Pressure coefficient 
    Cf= 1.65;	//Thrust coefficient
    
    printf("\n\nWelcome to the QuantumRocketry! \n All The Calculations For Your Rocket Will Be Done Here.... \n Get Ready To Input Your Data..\n");
    printf("\n\nMotor Chamber:\n");
    printf("\nChamber Diameter in mm(Dc): ");
    scanf("%lf", &Dc);
    printf("Chamber Length in mm(Lc): ");
    scanf("%lf", &Lc);
    printf("Propellant Grain: \n");
    printf("\nGrain Outer Diameter in mm(Do): ");
    scanf("%lf", &Do);
    printf("Core Diameter in mm(do): ");
    scanf("%lf", &d);
    printf("Grain Length in mm(Lo): ");
    scanf("%lf", &Lo);
    printf("Number of Segments(N): ");
    scanf("%lf", &N);

    while(flag)
    {
    printf("\nTargeted Chamber Pressure in Psi(MCP): ");
    scanf("%lf", &MCP);
    
    if (MCP>=150 && MCP<450)
    {
    Knmax= 216;
    flag=0;
    }
    else if(MCP>=450 && MCP<900)
    {
    Knmax = 286;
    flag =0;
    }
    else if(MCP>=900)
    {
    Knmax = 299;
    flag = 0;
    }
    else
    printf("\nError!\nThe Value is less than 150.\nThe MCP value should be above 150.\n");
    }

    Vc = 3.14/4*pow(Dc,2)*Lc;			 //Volume of Chamber in mm^3
    Lgo = N*Lo; 				// Total Grain Length in mm
    Vg = 3.14/4*(pow(Do,2)-pow(d,2))*Lgo;		//Grain Volume mm^3
    mg = p*Vg; 				//grain mass in gram
    Abmax = 3.14*d*Lgo;			//Core Burning Area mm^2
    At = Abmax/Knmax; 			//Throat Cross-sectional area mm^2
    v = 1/(1-n);                // variable
    s = (K+1)/(K-1);            // variable
    m = 2/(K+1);                // variable
    b = K/(R*To);               // variable
    i = sqrt(b*pow(m,s));       // variable
   

    fp = fopen("xKn.txt", "w");
    mp = fopen("tPo.txt", "w");     
    sp = fopen("tF.txt", "w");
    ip = fopen("Por.txt", "w");
    x =0;
    t = 0;
    printf("\n\n%s \t \t %s\t\t\t%s \t \t    %s \t \t %s       \t \t \t\t%s \n", "x", "Kn", "Po", "r", "F", "t");
    while(di <= Do)
    {
        di=d+ 2* x;                 //Instantaneous Core Diameter(mm)
        Ab= 3.14 * di* di / 4;      //Instantaneous Burning Area(mm^2)
        Kn= Ab/At;                  //Instantaneous Kn
        j = Kn*a*p/i;               
        Po = pow(j,v);               //Instantaneous Chamber Pressure(Pa)
        r = a*pow(Po,n);             //Instantaneous Burn Rate(mm/s)
        F = Cf*At*Po;                //Instantaneous Force(N)
        t = (0.5/r)+t;               //Instantaneous Time(s)
        x+=0.5;                      //Instantaneous Grain Regression(mm)

        printf("\n%lf \t %lf   \t %lf \t \t %lf \t %lf \t \t %lf \n", x, Kn, Po, r, F, t );
        fprintf(fp,"%lf \t %lf \n", x, Kn);
        fprintf(mp,"%lf \t %lf \n", t, Po);
        fprintf(sp,"%lf \t %lf \n", t, F);
        fprintf(ip,"%lf \t %lf \n", Po, r);
    }
  

    fclose(fp);
    fclose(mp);
    fclose(sp);
    fclose(ip);


}