#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


    srand(time(0));          // seed random number
    // variables
    string fileType;         // vaiable to hold the menu choise of the type of file
    string qualityType;      // variable to hold the menu choice of the file quality
    double bitrate;          // variable to hold bitrate
    string monoStereo;       // varaibl to hold menu choice
    int minutes;             // variable to hold minutes
    int seconds;             // variable to hold seconds
    double duration;         // variable to hold the calculated duration
    double subtotal;         // cariable to hold subtotal
    double fileSize;         // variable to hold the calculated cost per file size
    double costPerMin;       // variable to hold the calculated cost per minute
    double costperMB;        // variable to hold the calculated cost per mb of usage
    double tax;              // variable to hold the calculated streaming tax
    double total;            // variavle to hold final cost
    string menuChoice;       // variable to hold the main menu choice
    int numRecordings;       // variable to hold the number of recordings to be generated
    int randFileType;        // variable to hold the randomly generated file type
    int randQuality;         // variable to hold the randomly generated file quality
    int randMonoStereo;      // variable to hold the randomly generated mono / stereo wav type
    double totalMB = 0;      // variable to hold the total MB for random generated recordings
    int totalMinutes = 0;    // variable to hold the total minutes for random generated recordings
    int totalSeconds = 0;    // variable to hold the total seconds for random generatd recordings
    double totalCost = 0;    // varaible to hold the total cost for random generated recordings
    string output = "";      // vaiable to hold the output of the file

    //named constants
    const double MP3STANDARD = 1.20;
    const double MP3PREMIUM = 1.44;
    const double MP3ULTRA = 2.40;
    const double MONOSTANDARD = 5.29;
    const double MONOPREMIUM = 8.64;
    const double MONOULTRA = 17.28;
    const double STEREOSTANDARD = 10.58;
    const double STEREOPREMIUM = 17.28;
    const double STEREOULTRA = 34.56;
    const double SUBTOTAL_A = 1.99;
    const double SUBTOTAL_B = 5.99;
    const double SUBTOTAL_C = 9.99;
    const double SUBTOTAL_D = 12.99;
    const double TAXRATE = 0.0723;

    // Function prototypes
    string getMainMenuChoice();
    string getFileType();
    string getQualityType(const string& fileType);
    string getMonoStereoChoice();
    int getDurationMinutes();
    int getDurationSeconds(int minutes);
    double calculateDuration(int minutes, int seconds);
    double calculateSubtotal(double duration);
    double calculateFileSize(double duration, double bitrate);
    double calculateCostPerMinute(double subtotal, double duration);
    double calculateCostPerMB(double subtotal, double fileSize);
    double calculateTax(double subtotal);
    double calculateTotalCost(double subtotal, double tax);


    // format show two decimal places of float point 
    cout << setprecision(2) << showpoint << fixed;
    int main()
    {
    // display  header
    cout << "Welcome to SmoothTunes! \n\n";
    string getMainMenuChoice() {
    string menuChoice;
    do{
        // display the main menu
        cout << "Main Menu \n";
        cout << "\tA - Process a Single Recording File \n";
        cout << "\tB - Process Multiple Recording Files \n";
        cout << "\tC - Quit \n\n";
        cout << "Enter choice of action: ";
        getline(cin, menuChoice);
        return menuChoice;
    }

        if(menuChoice == "A" or menuChoice == "a" )
        {
            // Project 1 - Single Recording
            // display the file type menu
            cout << "\nChoose your file type: ";
            cout << "\n\t A - MPEG Layer 3 (MP3)";
            cout << "\n\t B - Waveform Audio File Format (WAV)";
            cout << "\n\nEnter your choice of file type (A or B): ";
            getline(cin, fileType);

            //validate the input
            while(fileType != "A" and fileType != "B" and fileType != "a" and fileType != "b")
            {
                cout << "\nError: Invalid file type. Try again. \n";
                cout << "Choose your file type: ";
                cout << "\n\t A - MPEG Layer 3 (MP3)";
                cout << "\n\t B - Waveform Audio File Format (WAV)";
                cout << "\n\nEnter your choice of file type (A or B): ";
                getline(cin, fileType);
            }

            //validate input
            if(fileType == "A" or fileType == "a")
            {
                // start the MP3 file output string
                output += "File Type: MP3 \nFile Quality: ";

                // MP3 File
                cout << "\nChoose your MP3 file quality:";
                cout << "\n\t A - Standard Quality - 160kbps";
                cout << "\n\t B - Premium Quality - 192kbps";            
                cout << "\n\t C - Ultra Quality - 320 kbps";                
                cout << "\n\nEnter your choice of file quality (A, B, or C): ";
                getline(cin, qualityType);

                // validate the input of the file quality
                while(qualityType != "A" and qualityType != "a" and
                    qualityType != "B" and qualityType != "b" and
                    qualityType != "C" and qualityType != "c")
                {
                    cout << "\nERROR: Invalid quality type. Try again. \n.";
                    cout << "\nChoose your MP3 file quality:";
                    cout << "\n\t A - Standard Quality - 160kbps";
                    cout << "\n\t B - Premium Quality - 192kbps";            
                    cout << "\n\t C - Ultra Quality - 320 kbps";                
                    cout << "\n\nEnter your choice of file quality (A, B, or C): ";
                    getline(cin, qualityType);
                }   
        
                // quality type choice
                if(qualityType == "A" or qualityType == "a")
                {
                    // MP3 Standard Quality
                    bitrate = MP3STANDARD;
                    // add on the standard file equality
                    output += "Standard - 160kbps";
                }
                else if(qualityType == "B" or qualityType == "b")
                {
                    // MP3 Premium Quality
                    bitrate = MP3PREMIUM;
                    // add on the premium file equality
                    output += "Premium - 192kbps";
                }
                else
                {
                    // MP3 Ultra Quality
                    bitrate = MP3ULTRA;
                    // add on the ultra file equality
                    output += "Ultra - 320kbps";
                }
            }
            else
            {
                // WAV File
                // start the wavefile output string
                output += "File Type: WAV";

                // menu for WAV file sound type
                cout << "\nChoose your sound type: ";
                cout << "\n\t A - Mono";
                cout << "\n\t B - Stereo";
                cout << "\n\nEnter your choice of sound type (A or B): ";
                getline(cin, monoStereo);

                // validate the iput of the sound type
                while(monoStereo != "A" and monoStereo !="B" and monoStereo != "a" and monoStereo != "b")
                {
                    cout << "\nERROR: Invalid sound type. Try again. \n";
                    cout << "\nChoose your sound type: ";
                    cout << "\n\t A - Mono";
                    cout << "\n\t B - Stereo";
                    cout << "\n\nEnter your choice of sound type (A or B): ";
                    getline(cin, monoStereo);
                }

                // get the input of the WAV File quality
                cout << "\nChoose your WAV file quality: ";
                cout << "\n\t A - Standard Quality - 16 bit, 44.1 KHz";
                cout << "\n\t B - Premium Quality - 24 bit, 48 KHz";
                cout << "\n\t C - Ultra Quality - 24 bit, 96 KHz";
                cout << "\n\nEnter your choice of file quality (A, B, or C): ";
                getline(cin, qualityType);

                // validate the input of the WAV file quality
                while(qualityType != "A" and qualityType != "a" and
                    qualityType != "B" and qualityType != "b" and
                    qualityType != "C" and qualityType != "c")
                {
                    cout << "n\ERROR: Invalid quality type. Try again. \n";
                    cout << "\nChoose your WAV file quality:";
                    cout << "\n\t A - Standard Quality - 16 bit, 44.1 KHz";
                    cout << "\n\t B - Premium Quality - 24 bit, 48 KHz";
                    cout << "\n\t C - Ultra Quality - 24 bit, 96 KHz";
                    cout << "\n\nEnter your choice of file quality (A, B, or C): ";
                    getline(cin, qualityType);
                }

                // check for the sound type
                if (monoStereo == "A" or monoStereo == "a")
                {
                    // Mono sound type
                    // add mono sound type to the output string
                    output += "\nSound Type: Mono \nFile Quality: ";

                    // determine the bitrate
                    if(qualityType == "A" or qualityType == "a")
                    {
                        // standard mono wav file
                        bitrate = MONOSTANDARD;
                        // add on the output string
                        output += "Standard - 16 bit, 44.1 kHz";
                    }
                    else if(qualityType == "B" or qualityType == "b")
                    {
                        // premium mono wav file
                        bitrate = MONOPREMIUM;
                        // add on to the output string
                        output += "Premium - 24 bit, 48 kHz";
                    }
                    else
                    {
                        // ultra mono wav file
                        bitrate = MONOULTRA;
                        // add on the output string
                        output += "Ultra - 24 bit, 96 kHz";
                    }
                }
                else
                {
                    // Stereo sound type
                    // add the stereo sound type to the output string
                    output += "\nSound Type: Stereo \nFile Quality: ";

                    // determine the bitrate
                    if(qualityType == "A" or qualityType == "a")
                    {
                        // standard stereo wav file
                        bitrate = STEREOSTANDARD;
                        // add on the output string
                        output += "Standard - 16 bit, 44,1 kHz";               
                    }
                    else if(qualityType == "B" or qualityType == "b")
                    {
                        // premium stereo wav file
                        bitrate = STEREOPREMIUM;
                        // add on the output string
                        output += "Premium - 24 bit, 48 kHz";
                    }
                    else
                    {
                        // ultra stereo wav file
                        bitrate = STEREOULTRA;
                        // add on to the output string
                        output += "Standard - 24 bit, 96 kHz";
                    }
                }
            }

            // get the input of the minutes from the user
            cout << "\nEnter the duration of the recording in minutes and seconds. (Max: 180 minutes)";
            cout << "\n\t Enter the miuntes: ";
            cin >> minutes;

            // validate the input of the minutes
            while(minutes < 0 or minutes > 180)
            {
                cout << "\nERROR: Invalid minutes entered. Try again.";
                cout << "\nEnter the duration of the recording in minutes and seconds. (Max: 180 minutes)";
                cout << "\n\t Enter the miuntes: ";
                cin >> minutes;
            }

            if(minutes == 180)
            {
                // set the seconds equal to 0
                seconds = 0;
            }
            else 
            {
                // get the input of seconds from the user
                cout << "\n\t Enter the seconds (Max 60): ";
                cin >> seconds;

                // validate the input of the seconds
                while(seconds < 0 or seconds > 60)
                {
                    cout << "\nERROR: Invalid seconds entered. Try again. \n";
                    cout << "\n\t Enter the seconds (Max 60): ";
                    cin >> seconds;
                }
            }

            // time calculation
            duration = minutes + (double)(seconds/60.0);

            // subtotal calculation
            if(duration <= 10)
                subtotal = SUBTOTAL_A;
            else if(duration <= 30)
                subtotal = SUBTOTAL_B;
            else if(duration <= 60)
                subtotal = SUBTOTAL_C;
            else
                subtotal = SUBTOTAL_D;

            // file size calculations
            fileSize = duration * bitrate;

            //cost per min
            costPerMin = subtotal / duration;

            // cost per MB
            costperMB = subtotal / fileSize;

            // calculate the streaming tax
            tax = subtotal * TAXRATE;

            // calculate the final cost
            total = subtotal + tax;

            // output
            cout << "\n---------------------" << endl;
            cout << output << endl << "Recording Duration: ";
            if (minutes == 1)
                cout << minutes << " minute";
            else if (minutes > 1)
                cout << minutes << " minutes";
                if (minutes == 180)
                    cout << endl;
            
            if (seconds == 1 and minutes >= 1)
                cout << ", 1 second" << endl;
            else if (seconds > 1 and minutes >= 1)
                cout << ", " << seconds << " seconds" << endl;
            else if (seconds == 1)
                cout << "1 second" << endl;
            else if (seconds > 1)
                cout << seconds << " seconds" << endl;

            cout << "File Size: " << fileSize << " MB" << endl;
            cout << "---------------------" << endl;
            cout << "Subtotal: $" << subtotal << endl;
            cout << "\t Cost Per Min: $" << costPerMin << "$/min" << endl;
            cout << "\t Cost Per MB: $" << costperMB << " $/MB" << endl;
            cout << "Streaming Tax: $" << tax << endl;
            cout << "Total Cost: $" << total << endl;

            cin.ignore(); // clear the buffer
        }
        else if(menuChoice == "B" or menuChoice == "b")
        {
            // Project 2 - Multiple Recordings

            // get the input of the number of recording to generate
            cout << "\Enter the number of recordings to generate (Min: 1, Max: 25): ";
            cin >> numRecordings;

            while(numRecordings < 1 or numRecordings > 25)
            {
                cout << "\nERROR: Invalid number of recordings entered. Try again, \n";
                cout << "\nEnter the number of recordings to generate (min: 1, max: 25): ";
                cin >> numRecordings;
            }

            cout << endl;

            // for loop to process the information about each randomly generated recording
            for(int r = 1; r <= numRecordings; r++)
            {
                // geneerate file type
                randFileType = 1 + rand() % 2;

                if(randFileType == 1)
                {
                    // mp3
                    // start the MP3 file output string
                    output += "File TYpe: MP3 \nFile Quality: ";

                    // generate the quality
                    randQuality = 1 + rand() % 3;

                    if(randQuality == 1)
                    {
                        bitrate = MP3STANDARD;
                        output += "Standard - 160kbps\n";
                    }
                    else if(randQuality == 2)
                    {
                        bitrate = MP3PREMIUM;
                        output += "Premium - 192kbps\n";
                    }
                    else
                    {
                        bitrate = MP3ULTRA;
                        output += "Ultra - 320kbps\n";
                    }
                }
                else
                {
                    // wav
                    output += "File Type: WAV";

                    // generate mono/stereo
                    randMonoStereo = 1 + rand() % 2;

                    // generate file quality
                    randQuality = 1 + rand() % 3;

                    if(randMonoStereo == 1)
                    {
                        // mono file
                        output += "\nSound Type: Mono \nFile Quality: \n";

                        if(randQuality == 1)
                        {
                            bitrate = MONOSTANDARD;
                            output += "Standard - 16 bit, 44.1 kHz \n";
                        }
                        else if(randQuality == 2)
                        {
                            bitrate = MONOPREMIUM;
                            output += "Premium - 24 bit, 48 kHz \n";
                        }
                        else
                        {
                            bitrate = MONOULTRA;
                            output += "Ultra - 24 bit, 96 kHz \n";
                        }
                    }
                    else
                    {
                        // stereo file
                        output += "\nSound Type: Stereo \nFile Quality: \n";

                        if(randQuality == 1)
                        {
                            bitrate = STEREOSTANDARD;
                            output += "Standard - 16 bit, 44.1 kHz \n";
                        }
                        else if(randQuality == 2)
                        {
                            bitrate = STEREOPREMIUM;
                            output += "Premium - 24 bit, 48 kHz \n";
                        }
                        else
                        {
                            bitrate = STEREOULTRA;
                            output += "Ultra - 24 bit, 96 kHz \n"; 
                        }
                    }
                }

                // generate the minutes 
                minutes = rand() % 180;
            
                // generate the seconds
                seconds = rand() % 60;

                // time calculation
                duration = minutes + (double)(seconds/60.0);

                // subtotal calculation
                if(duration <= 10)
                    subtotal = SUBTOTAL_A;
                else if(duration <= 30)
                    subtotal = SUBTOTAL_B;
                else if(duration <= 60)
                    subtotal = SUBTOTAL_C;
                else
                    subtotal = SUBTOTAL_D;

                // file size calculations
                fileSize = duration * bitrate;

                //cost per min
                costPerMin = subtotal / duration;

                // cost per MB
                costperMB = subtotal / fileSize;

                // calculate the streaming tax
                tax = subtotal * TAXRATE;

                // calculate the final cost
                total = subtotal + tax;

                // add on to total minutes
                totalMinutes += minutes;

                // add on to total leftover seconds
                totalSeconds += seconds;

                // add to total subtotal
                totalCost += subtotal;

                // add on to the file size
                totalMB += fileSize;

                cout << "Recording #" << r;
                cout << "\n---------------------" << endl;
                cout << output << "Recording Duration: ";
                if (minutes == 1)
                    cout << minutes << " minute";
                else if(minutes >  1)
                    cout << minutes << " minutes";

                if (seconds == 1 and minutes >=1)
                    cout << ", 1 second\n";
                else if (seconds > 1 and minutes >= 1)
                    cout << ", " << seconds << " seconds\n";
                else if (seconds == 1)
                    cout << "1 second\n";
                else if (seconds > 1)
                    cout << seconds << " seconds\n";
                
                cout << "File Size: " << fileSize << " MB" << endl;
                cout << "---------------------" << endl;
                cout << "Subtotal: $" << subtotal << endl;
                cout << "\t Cost Per Min: $" << costPerMin << "$/min" << endl;
                cout << "\t Cost Per MB: $" << costperMB << " $/MB" << endl;
                cout << "Streaming Tax: $" << tax << "\n";
                cout << "Total Cost: $" << total << "\n\n";

                // clear the output on each pass
                output = "";
            }

            // display the totals
            cout << "----------------\nTotals: \n";
            cout << "Number of recordings streamed: "<< numRecordings << endl;
            cout << "Total MB Streamed: " << totalMB << " MB \n";
            cout << "Total Duration of streams: " << totalMinutes + (totalSeconds/60) << " minutes, "
                 << (totalSeconds % 60) << " seconds \n";
            cout << "Total cost of all streams: $" << (totalCost + (totalCost * TAXRATE)) << endl << endl;

            // reset the running total
            totalMB = 0;
            totalMinutes = 0;
            totalSeconds = 0;
            totalCost = 0;

            cin.ignore();
        }
        else if(menuChoice == "C" or menuChoice == "c")
        {
            // Exit the program
            cout << "\nThank you for using the program. \n\n";
        }
        else
        {
            // input validation
            cout << "\nERROR: INVALID MENU CHOICE. TRY AGAIN, \n\n";
        }

    }while(menuChoice != "C" and menuChoice != "c");
}