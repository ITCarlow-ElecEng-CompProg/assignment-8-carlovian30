/**Kevin Griffin
 * Lab ex-8
 * Operational A<plifier circuit
 */

/**< preprocessor directives */
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <cmath>
using namespace std;


/**< main function */
int main(void)
{
    /**Global decalarations**/
    void inverting_amplifier(void);
    void nonInvertingAmp(void);
    char displaymenu(void);


	char choice;


	/**<do while menu selection to call functions
    and will remain running until q is pressed */

   do
    {
        choice = displaymenu();

            switch (choice)
        {
            case 'a' :  inverting_amplifier();
                        break;

            case 'b' :  nonInvertingAmp();
                        break;

            case 'q' :  system("cls");
                        cout << "Goodbye" << endl;
                        break;

            default :   cout << "invalid selection" << endl;
                        break;
        }
    }
    while (choice != 'q');

    return 0;
}


/** Menu display to prompt the user to select a invertor*/
char displaymenu(void)
{
    char choice;

    /**clears the screens*/
    system("cls");

    /** menu options for the user*/
    cout << "Operational Amplifier circuits\n \n";
    cout << "press a for Av and Vout for inverting Op Amp\n";
    cout << "press b for Av and Vout for non-inverting Op Amp \n";
    cout << "Press q to quit \n \n ";

    /** returns the users choice*/
    choice = getchar();

    return choice;
}

/**Function for inverting amp*/
void inverting_amplifier(void)
{
    /** variable declaratins*/
    double Vcc, Vee, Vin, Rin, Rf, Vout, Av;
    double *av_ptr = &Av, *vout_ptr = &Vout;

    /**clears the screen*/
    system("cls");

    /** Cart to pol calculation variables*/
    void invertingAmpCalculation(double, double, double , double, double, double *, double *);

    /**tells the user the selected Calculator is*/
    cout << "Inverting Amplifier Calculations\n\n" << endl;


    /** prompts the users to enter real value*/
    cout << "Enter value for Vcc"<< endl;
    cin >> Vcc;

    /** prompts the users to enter Vee value*/
    cout << "Enter value Vee:\t" << endl;
    cin >> Vee;

    /** prompts the users to enter Vee value*/
    cout << "Enter value for Vin"<< endl;
    cin >> Vin;

    /** prompts the users to enter Vee value*/
    cout << "Enter value for Rin"<< endl;
    cin >> Rin;

    /** prompts the users to enter Vee value*/
    cout << "Enter value for Rf"<< endl;
    cin >> Rf;


    /**Calls the calculating function*/
    invertingAmpCalculation(Vcc, Vee, Vin, Rin, Rf, vout_ptr, av_ptr);


    /**Displays the results for Av an Vout*/
     cout << Av << " Gain is : " << endl;

     cout << Vout << " Vout is : " << endl;

     /**prompts the user to hit enter to return to the main menu*/
     cout << "Press Enter to Continue";

     /** holds the program until any key is hit*/
     getch();

    return;
}

/**function to calcualate the gain and Vout from the amplifier*/
void invertingAmpCalculation(double Vcc, double Vee, double Vin, double Rin, double Rf, double *Vout, double *Av)
{
    /**Equation to calculate the gain and Vout*/
    *Av = - Rf/Rin;
    *Vout = *Av * Vin;

    /**Conditional statement that ensure that the max volatage, or saturation, is not exceeded.
    if the volatage is exceeded then Vout it equaled to max Vcc or Vee*/
    if ((*Av * Vin) < Vee)
    {
        *Vout = Vee;
    }

    else if ((*Av * Vin) > Vcc)
    {
        *Vout = Vcc;
    }

    else
    {
        *Vout = *Av * Vin;
    }

    return ;
}


/**nonInvertingAmp function*/
void nonInvertingAmp(void)
{
    /**local variable decalrations*/
    double Vcc, Vee, Vin, R1= 0, R2=0, Vout, Av;
    double *Vout_ptr, *Av_ptr;

    /**initalises the pointers*/
    Vout_ptr = &Vout;
    Av_ptr = &Av;

    /**clears the screen*/
    system("cls");

    /**calls the calculator function*/
    void nonInvertingAmpCalculation(double, double, double , double, double, double *, double *);

    /**Informs the user of the type of calculator selected*/
    cout << "Polar to Cartesian Conversion\n\n" << endl;



    /**prompts the user to enter a value for Vcc*/
    cout << "Enter a value for Vcc: "<< endl;
    cin >> Vcc;


    /**prompts the user to enter a value for Vee*/
    cout << "Enter a value for Vee : "<< endl;
    cin >> Vee;


    /**prompts the user to enter a value for Vin*/
    cout << "Enter a value for Vin: "<< endl;
    cin >> Vin;


    /**prompts the user to enter a value for R1*/
    while (R1<=0)
    {
        cout << "Enter a value for positive value for R1: "<< endl;
        cin >> R1;
    }


    /**prompts the user to enter a value for R2*/
    while (R2<=0)
    {
        cout << "Enter a positive value for R2: "<< endl;
        cin >> R2;
    }

    /**calls the function to calculate the gain and vout*/
    nonInvertingAmpCalculation(Vcc, Vee, Vin, R1, R2, Vout_ptr, Av_ptr);


    /**Displays the results for real and imag*/
    cout << Av << "Gain is : " << endl;
    cout << Vout << "Vout is :" << endl;


    /**prompts the user to hit enter to return to the main menu*/
    cout << "Press Enter to Continue";


    /** holds the program until any key is hit*/
    getch();

    return;
}

/** non-invertingamp gain and vout calculator function*/
void nonInvertingAmpCalculation(double Vcc, double Vee, double Vin, double R1, double R2, double *Vout_Ptr, double *Av_ptr)
{
    /**Equations to calculate the gain and Vout*/
    *Av_ptr = 1 + R2/R1;
    *Vout_Ptr = *Av_ptr * Vin;

    /**Conditional statement that ensures that the max volatage, or saturation, is not exceeded.
    if the volatage is exceeded then Vout is equaled to max Vcc or Vee*/
    if (*Vout_Ptr < Vee)
    {
        *Vout_Ptr = Vee;
    }

    else if (*Vout_Ptr > Vcc)
    {
        *Vout_Ptr= Vcc;
    }

    else
    {
        *Vout_Ptr = *Av_ptr * Vin;
    }

    return;
}






