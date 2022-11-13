#include "authorization.h"

  void authorization:: menu(){
      int menu_choice;
      std::cout << "\t\t\t__________________________________________________\n\n\n";
      std::cout << "\t\t\t            Welcome to the Login page             \n\n\n";
      std::cout << "\t\t\t__________________      MENU     _________________\n\n\n";
      std::cout << "                                                          \n\n";
      std::cout << "\t| Press 1 to LOGIN                       |"<< std::endl;
      std::cout << "\t| Press 2 to REGISTER                    |"<< std::endl;
      std::cout << "\t| Press 3 if you forgot your PASSWORD    |"<< std::endl;
      std::cout << "\t| Press 4 to EXIT                        |"<< std::endl;
      std::cout << "\n\t\t\t Please enter your choice: ";
      std::cin >> menu_choice;
      std:: cout << std::endl;

      switch(menu_choice){
          case 1:
              authorization::login();
              break;
          case 2:
              authorization::registration();
              break;
          case 3:
              authorization::forgot();
              break;
          case 4:
              std::cout << "\t\t\t Thank you! Goodbye! \n\n";
              break;
          default:
              std::cout << "\t\t\t Please select from options given above \n\n";
              menu();
      }
}


  void authorization::login(){
    int count;
    std::string username, password, name, pass;

    std::cout << "\t\t\t Please enter your username and password: " << std::endl;
    std::cout << "\t\t\t USERNAME ";
    std::cin >> username;
    std::cout << std::endl;
    std::cout << "\t\t\t PASSWORD ";
    std::cin >> password;

    std::ifstream infile ("records.txt");

    while(infile >> name >> pass){
        if(name == username && pass == password){
            count  = 1;
        }
    }
    infile.close();

    if(count == 1){
        std::cout << "\n Your LOGIN is successful! \n Good Luck!\n";
        menu();
    }else{
        std::cout << "\n LOGIN ERROR! \n Please check your username and password\n";
        menu();
    }
}

void authorization::registration(){
    std::string rusername, rpassword, rname, rpass;

    std::cout << "\t\t\t Enter the username: ";
    std::cin >> rusername;
    std::cout << std::endl;
    std::cout << "\t\t\t Enter the password: ";
    std::cin >> rpassword;

    std::ofstream outfile("records.txt", std::ios::app);   //you can only write to the end of the file
    outfile << rusername << ' ' << rpassword << std::endl;
    std::cout << "\n\t\t\t Registration is successful! \n";
    menu();
}

void authorization::forgot(){
    int forgot_choice;
    std::cout << "\t\t\t You forgot the password? No worries. \n";
    std::cout << "Press 1 to search your id by username " << std::endl;
    std::cout << "Press 2 to go back to the main menu " << std::endl;
    std::cout << "\t\t\t Please enter your choice: ";
    std::cin >> forgot_choice;

    switch(forgot_choice){
        case 1: {
            int count = 0;
            std::string fusername, fname, fpass;
            std::cout << "\n\t\t\t Enter the username which you remembered: ";
            std::cin >> fusername;

            std::ifstream infile2("records.txt");
            while(infile2 >> fname >> fpass){
                if(fname == fusername){
                    count = 1;
                }
            }
            infile2.close();
            if(count == 1){
                std::cout << "\nYour account is found!" << std::endl;
                std::cout << "Your password is: " << fpass << std::endl;
                menu();
            }else{
                std::cout << "\n\t Sorry! Your account is not found!";
                std::cout << "\n\t Try again.\n";
                menu();
            }
            break;
        }
        case 2: {
            menu();
        }
        default: {
            std::cout << "\t\t\t Wrong choice! Please try again. " << std::endl;
            forgot();
        }
    }
}