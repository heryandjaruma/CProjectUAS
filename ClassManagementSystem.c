/**
 * @file ClassManagementSystem.c
 * @author Heryan Djaruma, Raihan Elta, Yulia Puspitasari
 * @brief Algorithm and Programming Final Project
 * 
 */



/************************* LIBRARY IMPORT & PREPROCESSOR *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define true 1
#define false 0



/************************* DEFINE GLOBAL VARIABLES *************************/
/**
 * @brief All data stored in struct. An array of struct is initialized with the value of SIZE (100)
 */
struct Student
{
   char name[26], nim[11];
   int asg, mid, fin;
} students[SIZE];

/**
 * @brief used to count current number of data in the array.
 */
int count = 0;

/**
 * @brief used to keep track on how many data has not been filled completely.
 * If this variable is not in value of 0, program will redirect user to fill them out.
 */
int na = 0;

/**
 * @brief store real index of unfilled data.
 */
int real_index[100];



/************************* USER DEFINED FUNCTIONS *************************/
/**
 * @brief clear screen
 * @author Yulia Puspitasari
 */
void cls(){
   system("cls");
}

/**
 * @brief common function
 * @author Raihan Elta
 */
void enter_to_continue(){
   printf("Press enter to continue . . .");
   getchar();
}

/**
 * @brief used in show_student_data_newly_inserted() and input_student()
 * @author Yulia Puspitasari
 */
void header_add_student(){
   puts("=========================");
   puts("***    ADD STUDENT    ***");
   puts("=========================\n");
}

/**
 * @brief used in unfilled_student()
 * @author Yulia Puspitasari
 */
void header_unffilled_student(){
   puts("--------------------------------------------------------------------------------");
   puts("|| No  |          NAME             |    NIM     |   ASG   |   MID   |   FIN   ||");
   puts("--------------------------------------------------------------------------------");
}

/**
 * @brief used in show_student_data() 
 * @author Yulia Puspitasari
 */ 
void header_show_student_data(){
   puts("==========================");
   puts("***    STUDENT DATA    ***");
   puts("==========================\n");
}

/**
 * @brief used in print_student()
 * @author Yulia Puspitasari
 */
void header_print_student(){
   puts("==========================================================================");
   puts("**********                    STUDENTS DATA                     **********");
   puts("==========================================================================\n");
}

/**
 * @brief used in print_student()
 * @author Yulia Puspitasari
 */
void header_student_list(){
   puts("--------------------------------------------------------------------------");
   puts("||          NAME             |    NIM     |   ASG   |   MID   |   FIN   ||");
   puts("--------------------------------------------------------------------------");
}

/**
 * @brief used in main_menu()
 * @author Raihan Elta
 */
void header_main_menu(){
   cls();
   puts(" __   _    __  __  __      ");     
   puts("/ /` | |  / /\\( (`( (`    ");
   puts("\\_\\_,|_|_/_/--\\)_)_)_)    ");
   puts(" _     __  _     __  __  _____    _____  _____     ");
   puts("| |\\/|/ /\\| |\\ |/ /\\/ /`| |_| |\\/| |_| |\\ | |     ");
   puts("|_|  /_/--\\_| \\/_/--\\_\\_/_|_|_|  |_|_|_| \\|_|     ");
   puts(" __  _   ___________");
   puts("( (`\\ \\_( (`| | |_| |\\/|");
   puts("_)_) |_|_)_)|_|_|_|_|  |");
   puts("\n==============================================");
   puts("****              MAIN MENU               ****");
   puts("==============================================");
   puts("1. Add Student");
   puts("2. Enter Evaluation Result");
   puts("3. Show All Data");
   puts("0. Exit");
   puts("");
   printf(">> ");
}

/**
 * @brief used in write_to_file()
 * @author Yulia Puspitasari
 */
void exit_credit(){
   puts("CREDITS:");
   puts("====  GROUP 4  ====");
   puts("[Heryan Djaruma - 2502028140]\n[Raihan Elta - 2501996013]\n[Yulia Puspitasari - 2501996436]\n");
}


/**
 * @brief push value into the struct. Initializing all scores with -1 as well.
 * @param name value that will be inserted
 * @param nim value that will be inserted
 * @author Heryan Djaruma
 */
void push_data_name_nim(char *name, char *nim){
   strcpy(students[count].name, name);
   strcpy(students[count].nim, nim);
   students[count].asg = -1;
   students[count].mid = -1;
   students[count].fin = -1;
}

/**
 * @brief Set the default score object
 * @param index of struct in the array
 * @author Raihan Elta
 */
void set_default_score(int index){
   students[index].asg = -1;
   students[index].mid = -1;
   students[index].fin = -1;
}

/**
 * @brief push value into the already created struct. Used in read_from_file().
 * @param i is the index of data in the array
 * @param asg value of Assignment Score
 * @param mid value of Middle Term Score
 * @param fin value of Final Term Score
 * @author Raihan Elta
 */
void push_data_score(int i, int asg, int mid, int fin){
   students[i].asg = asg;
   students[i].mid = mid;
   students[i].fin = fin;
}

/**
 * @brief push Assignment Score value to the struct with index i
 * @param i is the index of data in the array
 * @param asg value of Assignment Score
 * @author Raihan Elta
 */
void push_asg_score(int i, int asg){
   students[i].asg = asg;
}

/**
 * @brief push Middle Term Score value to the struct with index i
 * @param i is the index of data in the array
 * @param mid value of Middle Term Score
 * @author Raihan Elta
 */
void push_mid_score(int i, int mid){
   students[i].mid = mid;
}

/**
 * @brief push Final Term Score value to the struct with index i
 * @param i is the index of data in the array
 * @param fin value of Final Term Score
 */
void push_fin_score(int i, int fin){
   students[i].fin = fin;
}

/**
 * @brief push name into the desired struct
 * @param index is the index of data in the array
 * @author Raihan Elta
 */
void push_name(int index){
   char name[26];
   do
   {
      printf("Enter student's name [max. 25 character]      : ");
      gets(name);
   } while (strlen(name) < 1 || strlen(name) > 25);
   strcpy(students[index].name, name);
}

/**
 * @brief push nim into the desired struct
 * @param index is the index of data in the array
 * @author Raihan Elta
 */
void push_nim(int index){
   char nim[11];
   do
   {
      printf("Enter student's nim [10 numeric characters]   : ");
      gets(nim);
   } while (strlen(nim) != 10);
   strcpy(students[index].nim, nim);
}

/**
 * @brief to show newly created data for confirmation
 * @param index index of the struct in the array
 * @author Yulia Puspitasari
 */
void show_student_data_newly_inserted(int index){
   cls();
   header_add_student();
   printf("Name   : %s\n", students[index].name);
   printf("NIM    : %s\n\n", students[index].nim);
}

/**
 * @brief input student into array but only its name and nim
 * @author Raihan Elta
 */
void input_student(){
   cls();
   header_add_student();
   push_name(count);
   push_nim(count);
   show_student_data_newly_inserted(count);

   puts("Student Successfully Added!");
   enter_to_continue();
   count++;
}

/**
 * @brief sort based on Asg score
 * @author Yulia Puspitasari
 */
void sort_asg(){
   for (int i = 0; i < count; i++)
   {
      for (int j = 0; j < count-i-1; j++)
      {
         if (students[j].asg == -1 || students[j].mid == -1 || students[j].fin == -1) continue;
         if (students[j].asg > students[j+1].asg)
         {
            struct Student temp = students[j];
            students[j] = students[j+1];
            students[j+1] = temp;
         }
      }
   }
}

/**
 * @brief sort based on Mid score
 * @author Yulia Puspitasari
 */
void sort_mid(){
   for (int i = 0; i < count; i++)
   {
      for (int j = 0; j < count-i-1; j++)
      {
         if (students[j].asg == -1 || students[j].mid == -1 || students[j].fin == -1) continue;
         if (students[j].mid > students[j+1].mid)
         {
            struct Student temp = students[j];
            students[j] = students[j+1];
            students[j+1] = temp;
         }
      }
   }
}

/**
 * @brief sort based on Fin score
 * @author Yulia Puspitasari
 */
void sort_fin(){
   for (int i = 0; i < count; i++)
   {
      for (int j = 0; j < count-i-1; j++)
      {
         if (students[j].asg == -1 || students[j].mid == -1 || students[j].fin == -1) continue;
         if (students[j].fin > students[j+1].fin)
         {
            struct Student temp = students[j];
            students[j] = students[j+1];
            students[j+1] = temp;
         }
      }
   }
}

/**
 * @brief ask user in what order the data will be shown 
 * @return int value of chosen option
 * @author Heryan Djaruma
 */
int choose_by(){
   char choose[5];
   while (true)
   {
      printf("SORT BY [\"ASG\" | \"MID\" | \"FIN\" | \"BACK\" to exit] >> ");
      gets(choose);
      if (strcmp(choose, "ASG") == 0) {
         return 1;  
      } else if (strcmp(choose, "MID") == 0) {
         return 2;
      } else if (strcmp(choose, "FIN") == 0) {
         return 3;
      } else if (strcmp(choose, "BACK") == 0) {
         return 0;
      } else continue;
   }
   return -1;
}

/**
 * @brief show list of students with unfilled scores. If this function returns 0, it means all students have the data been filled by user.
 * @return int the number of student with unfilled scores
 * @author Heryan Djaruma
 */
int print_unfilled_student(){
   header_unffilled_student();
   
   int how_many_unfilled = 0;

   for (int i = 0; i < count; i++)
   {
      if (students[i].asg == -1 || students[i].mid == -1 || students[i].fin == -1)
      {
         printf("|| %-3d | %-25s | %-10s | %-7s | %-7s | %-7s ||\n", how_many_unfilled+1, students[i].name, students[i].nim, "N/A", "N/A", "N/A" );
         real_index[how_many_unfilled] = i;
         how_many_unfilled++;
      } else continue;
   }
   puts("");
   return how_many_unfilled;
}

/**
 * @brief ask user which student will be filled
 * @param max_index maximum number of student which doesn't have the scores filled in. This function will only be shown if there's any students without score. Otherwise, confirmtion page will appear.
 * @return int value of the chosen student
 * @author Heryan Djaruma
 */
int choose_to_fill(int max_index){
   int choose = -1;
   do
   {
      printf("Please choose a student to fill [1 - %d] >> ", max_index);
      scanf("%d", &choose);
   } while (choose < 1 || choose > max_index);
   return real_index[choose-1];
}

/**
 * @brief show student data which just getting filled by the user as confirmation page. Note that this program accepts floating point, but will automatically round it based on the closest integer.
 * @param index value of the struct in the array
 * @author Heryan Djaruma
 */
void show_student_data(int index){
   cls();
   header_show_student_data();
   printf("Name   : %s\n", students[index].name);
   printf("NIM    : %s\n\n", students[index].nim);
   if (students[index].asg == -1) { printf("Assignment Score   : N/A\n");}
   else printf("Assignment Score   : %d\n", students[index].asg);
   
   if (students[index].mid == -1) { printf("Mid Term Score     : N/A\n");}
   else printf("Mid Term Score     : %d\n", students[index].mid);

   if (students[index].fin == -1) { printf("Final Term Score   : N/A\n");}
   else printf("Final Term Score   : %d\n", students[index].fin);

   puts("\nNOTE : floating point value will be automatically rounded\n");
}

/**
 * @brief validation to get asg score. Only accepts range 0 - 100. 
 * @param index value of struct in the array
 * @author Heryan Djaruma
 */
void insert_asg_score(int index){
   show_student_data(index);
   double value = -1;
   do
   {
      printf("Input Assignment Score   >> ");
      scanf("%lf", &value); getchar();
   } while (value < 0 || value > 100);
   push_asg_score(index,(int) value);
}

/**
 * @brief validation to get mid score. Only accepts range 0 - 100. 
 * @param index value of struct in the array
 * @author Heryan Djaruma
 */
void insert_mid_score(int index){
   show_student_data(index);
   double value = -1;
   do
   {
      printf("Input Mid Term Score     >> ");
      scanf("%lf", &value); getchar();
   } while (value < 0 || value > 100);
   push_mid_score(index, (int) value);
}

/**
 * @brief validation to get final score. Only accepts range 0 - 100. 
 * @param index value of struct in the array
 * @author Heryan Djaruma
 */
void insert_fin_score(int index){
   show_student_data(index);
   double value = -1;
   do
   {
      printf("Input Final Term Score   >> ");
      scanf("%lf", &value); getchar();
   } while (value < 0 || value > 100);
   push_fin_score(index, (int) value);
}

/**
 * @brief push all data to the struct, which was unfilled since it's initiated
 * @author Heryan Djaruma
 */
void input_evaluation_result(){
   cls();
   int max_index = print_unfilled_student();
   int index = choose_to_fill(max_index);
   insert_asg_score(index);
   insert_mid_score(index);
   insert_fin_score(index);
   
   show_student_data(index);
   puts("Score Successfully Inputed!");
   enter_to_continue();
}

/**
 * @brief print student without index, which used in print_student()
 * @author Heryan Djaruma
 */
void print_student_list_without_index(){
   for (int i = 0; i < count; i++)
   {
      if (students[i].asg == -1 || students[i].mid == -1 || students[i].fin == -1)
      {
         printf("|| %-25s | %-10s | %-7s | %-7s | %-7s ||\n", students[i].name, students[i].nim, "N/A", "N/A", "N/A" );
      } else{
      printf("|| %-25s | %-10s | %-7d | %-7d | %-7d ||\n", students[i].name, students[i].nim, students[i].asg, students[i].mid, students[i].fin);
      }
   }
}

/**
 * @brief used in the header of print_student()
 */
char sort_type[4][15] = {"", "ASSIGNMENT", "MID TERM", "FINAL TERM"};

/**
 * @brief print all data of the student
 * 
 * @param sort_by is the index of what order the data will be shown
 */
void print_student(int sort_by){
   header_print_student();
   if (sort_by == -1){
      puts("                     Sorted by : Please choose first!\n");
   } else {
      if (sort_by == 1){sort_asg(); }
      else if (sort_by == 2){sort_mid();}
      else if (sort_by == 3){sort_fin();}
      printf("                           Sorted by : %-16s\n\n", sort_type[sort_by]);
   }

   header_student_list();

   print_student_list_without_index();   
   puts("--------------------------------------------------------------------------\n");
}

/**
 * @brief output warning that tells user, all student's data have been filled out
 * @author Yulia Puspitasari 
 */
void input_score_exception(){
   cls();
   puts("All students' score have been filled out!");
   puts("You'll be redirected to score page.");
   enter_to_continue();
}

/**
 * @brief show user all data and ask user to sort by
 * @author Heryan Djaruma
 */
void print_student_with_sort(){
   int choose = -1;
   do
   {
      cls();
      print_student(choose);
      choose = choose_by();
   } while (choose != 0);
}

/**
 * @brief read all data present in the file
 * @author Heryan Djaruma
 */
void read_from_file(){
   FILE *fp = fopen("data.txt", "r");
   if (fp == NULL)
   {
      fp = fopen("data.txt", "w");
      fclose(fp);
      return;
   } else {
      while (!feof(fp))
      {
         char name[26], nim[11];
         int asg, mid, fin;
         fscanf(fp, "%[^#]#%[^#]#%d#%d#%d\n", name, nim, &asg, &mid, &fin);
         push_data_name_nim(name, nim);
         count++;
         push_data_score(count-1, asg, mid, fin);
         na--;
      }
      fclose(fp);   
   }
}

/**
 * @brief confirmation of unfilled student's score
 * @author Raihan Elta
 */
void score_unfilled(){
   cls();
   puts("Some students still have blank scores!");
   puts("You will be redirected to enter the score.\n");
   printf("Press enter to continue . . . ");
   getchar();
}

/**
 * @brief ask user to choose order of the data to write into file
 * 
 * @return int value of chosen option
 * @author Heryan Djaruma
 */
int save_by(){
   int choose = -1;
   do
   {
      cls();
      puts("How do you want this file saved (Order By)?");
      puts("1. Assignment");
      puts("2. Mid Term");
      puts("3. Final Term");
      printf("\n>> ");
      scanf("%d", &choose); getchar();
   } while (choose < 1 || choose > 3);
   return choose;
}

/**
 * @brief write all data in the struct into a file and sorted.
 * @author Heryan Djaruma 
 */
void write_to_file(){
   int by = save_by();
   if (by == 1) sort_asg();
   if (by == 2) sort_mid();
   if (by == 3) sort_fin();

   FILE *fp = fopen("data.txt", "w+");
   for (int i = 0; i < count; i++)
   {
      fprintf(fp, "%s#%s#%d#%d#%d\n", students[i].name, students[i].nim, students[i].asg, students[i].mid, students[i].fin);
   }
   fclose(fp);
   cls();
   puts("\nSuccessfully write into file!\n");

   exit_credit();

   printf("Press enter to exit . . .");
   getchar();
}

/**
 * @brief main menu / control of the program.
 * @author Heryan Djaruma
 */
void main_menu(){
   int choose = -1;
   do
   {
      header_main_menu();
      scanf("%d", &choose); getchar();    
      if (choose == 1)
      {
         input_student();
         set_default_score(count-1);
         na++;
         choose= -1;
      } else if (choose == 2)
      {
         if (na > 0){
            input_evaluation_result();
            na--;
            choose = -1;
         } else {
            input_score_exception();
            print_student_with_sort();
            choose = -1;
         }
      } else if (choose == 3)
      {
         print_student_with_sort();
         choose = -1;
      } else if (choose == 0 && na > 0)
      {
         score_unfilled();
         input_evaluation_result();
         na--;
         choose = -1;
      }
   } while (choose < 0 || choose > 3);
}




/************************* MAIN PROGRAM *************************/
/**
 * @brief main program. Do 3 sequential things : read_from_file(), main_menu(), and write_to_file(). 
 * na is used to tell how many students have scores not filled out. Intialized by 0 because all data present in the file, is complete and doesn't have NULL value.
 * @return int execution successful without error
 * @author Heryan Djaruma
 */
int main(){
   read_from_file();
   na = 0;

   main_menu();

   write_to_file();
   return 0;
}