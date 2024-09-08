#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<string.h> //for string handling functions.
#include<ctype.h>
#pragma warning (disable : 4996)

#define MAX_SUBJECTS 10 
#define MAX_NAME_LENGTH 10
#define MAX_STUDENTS 100
#define STAFF_ID "KPKL12345"

//global varaiable
int  c, j, n;
int   quality_point, subject, studentCount = 1;
int   count_course_code = 1, current_sem, current_year;
char  name[21], course_codes[15][10], studentID[11];
float allSemCreditHours = 0, allsemQuality_point = 0, GPA, CGPA;
char yes_no;
double deansListCriteria = 3.75;
double honorsListCriteria = 3.5;

struct StudentInfo {
	char name[21];
	double GPA;
	double CGPA;
};
struct StudentInfo students[MAX_STUDENTS]; // Array to store student information
int studentList = 0; // Variable to keep track of the number of students
struct StudentInfo currentStudent;

//declare function
void logo();
void staffMode();
void studentMode();
void calculator();
void studentAcademic_Advise();
void displayAvailableCourses();
void additionalSubject();

//declare function logo 
void logo()
{
	printf("\n");
	printf("\t\t\t        _  __    _      _  \n");
	printf("\t\t\t       | |/ /___| |___ (_) \n");
	printf("\t\t\t       | ' </ _ \\ / -_)| | \n");
	printf("\t\t\t       |_|\\_\\___/_\\___|/ | \n");
	printf("\t\t\t                     |__/  \n");
	printf("\n");
	printf("\t\t\t        ___                   \n");
	printf("\t\t\t       | _ \\__ _ ___ __ _ _ _ \n");
	printf("\t\t\t       |  _/ _` (_-</ _` | '_|\n");
	printf("\t\t\t       |_| \\__,_/__/\\__,_|_|  \n");
	printf("\n");

	printf("\t\t\t      <WELCOME TO KOLEJ PASAR>\n");
	printf("\n");
	printf("\t\t  <KOLEJ PASAR GPA AND CGPA CALCULATOR SYSTEM>\n");
	printf("            !!!!!!!!!!PLEASE USE UPPERCASE TO USE OUR SYETEM!!!!!!!!!!\n");
	printf("\n");
}

int authenticateStaff() {
	char enteredID[50];

	printf("\n\nEnter Staff ID: ");
	scanf("%s", enteredID);

	if (strcmp(enteredID, STAFF_ID) == 0) {
		// Staff ID authenticated
		return 1; // Return 1 to indicate successful authentication
	}
	else {
		// Invalid ID
		printf("INVALID STAFF ID");
		return authenticateStaff(); // Return 0 to indicate authentication failure
	}
}

void staffMode() {
	//looping for Student NO.
	printf("\nStudent NO. %d\n", studentCount);
	studentCount++;

	//Input Student details
	printf("\nEnter Student's Name:");
	scanf("%s", &name);
	rewind(stdin);

	printf("Enter Student's ID  (ID FORMAT :KPKLXXXXX):");
	scanf("%s", &studentID);
	rewind(stdin);

	printf("Enter Student Current Semester Section (ONLY YEAR 1 AVAILABLE) \n");

	printf("\t\tYear: ");
	scanf("%d", &current_year);
	printf("\t\tSem: ");
	scanf("%d", &current_sem);
	rewind(stdin);

	if (current_year == 1 && current_sem == 1) { //YEAR 1 SEM 1
		printf("SEMESTER 1\n");
		calculator(); // Call function calculator 
	}
	else if (current_year == 1 && current_sem == 2) { //YEAR 1 SEM 2
		printf("SEMESTER 1\n");
		calculator();


		printf("\nSEMESTER 2\n");
		calculator();

	}

	else if (current_year == 1 && current_sem == 3) { //YEAR 1 SEM 3
		printf("SEMESTER 1\n");
		calculator();

		printf("\nSEMESTER 2\n");
		calculator();

		printf("\nSEMESTER 3\n");
		calculator();
	}

	//print out student result 
	struct StudentInfo currentStudent;
	printf("\nNEXT STUDENT ? (Y=YES, N=NO)\n");
	printf("PLEASE ENTER : ");
	getchar();
	scanf("%c", &yes_no);

	if (toupper(yes_no == 'Y')) {
		system("cls");
		staffMode();
	}
	else {

		system("cls");
		printf("\t====================STUDENT RESULT=================\n");
		printf("\t%-18s \t%-11s \t%-11s\n", "Student Name", "GPA", "CGPA");
		printf("\t===================================================\n");
		printf("\t%-18s \t%-11.2lf \t%-11.2lf\n", name, GPA, CGPA);

		if (allSemCreditHours >= 21) {
			printf("\t===================================================\n");
			printf(" \t\t STUDENT HAVE GRADUATED SUCCESSFUL!\n");
			printf("\t===================================================\n");
		}
		else if (allSemCreditHours < 21) {
			printf("\t===================================================\n");
			printf(" \t\tSTUDENT NEED TO REPEAT THIS COURSE\n");
			printf("\t===================================================\n");
		}

		if (GPA >= deansListCriteria) {
			printf("\n\t-------------------------------------------------\n");
			printf("\t\tStudent added to the Dean's List!\n");
			printf("\t-------------------------------------------------\n");
		}
		else if (GPA >= honorsListCriteria) {
			printf("\n\t-------------------------------------------------\n");
			printf("\t\tStudent added to the Honors List!\n");
			printf("\t-------------------------------------------------\n");
		}
		else {
			printf("\n\t-------------------------------------------------\n");
			printf("\t\tStudent don't have added any list\n");
			printf("\t-------------------------------------------------\n");
		}

	}
}

void calculator() {
	char grade[8];
	float point[20];
	float courseQualityPoint[MAX_SUBJECTS] = { 0 };
	float semesterCredit_hours = 0;
	float semesterQuality_Point = 0;
	float credit_hours[20];

	printf("How many subject in your semester: ");
	scanf("%d", &subject);
	printf("\n");

	//Enter Course code
	for (int n = 0; n < subject; n++) {
		printf("\tEnter Course Code %d:", n + 1);
		scanf("%s", &course_codes[n]);
	}

	for (int i = 0; i < MAX_SUBJECTS; i++)
	{
		courseQualityPoint[i] = 0;
	}

	//Grade
	printf("\n");
	printf("\n\t=====GRADE========\n");
	printf("WARNING ! PLEASE ENTER GRADE WITH UPPERCASE!\n");
	printf("[ A  = 4.00  ]\n");
	printf("[ A- = 3.75  ]\n");
	printf("[ B+ = 3.50  ]\n");
	printf("[ B  = 3.00  ]\n");
	printf("[ B- = 2.75  ]\n");
	printf("[ C+ = 2.50  ]\n");
	printf("[ C  = 2.00  ]\n");
	printf("[ F  = 0.00  ]\n\n");

	for (int c = 0; c < subject; c++) {
		printf("\tEnter Grade for %s:", course_codes[c]);
		scanf("%s", &grade[c]);
	}

	//GRADE TRANSFERING TO GRADE POINT 
	int p = 0;
	for (int c = 0; c < 8; c++) {
		if (grade[c] == 'A') {
			point[p] = 4.00;
			if (grade[c + 1] == '-') {
				point[p] = 3.75;
			}
			p++;
		}
		else if (grade[c] == 'B') {
			point[p] = 3.00;
			if (grade[c + 1] == '+') {
				point[p] = 3.50;
			}
			if (grade[c + 1] == '-') {
				point[p] = 2.75;
			}
			p++;
		}

		else if (grade[c] == 'C') {
			point[p] = 2.00;
			if (toupper(grade[c + 1] == '+')) {
				point[p] = 2.50;
			}
			p++;
		}
		else {
			point[p] = 0.00;
		}
	}

	//Credit Hours
	printf("\n");
	printf("\t=====CREDIT HOURS========\n");
	printf("CREDIT HOURS = 1,2,3,4 ONLY\n\n");

	for (int c = 0; c < subject; c++) {
		printf("\tEnter Credit Hours for %s (%d) : ", course_codes[c], c + 1);
		scanf("%f", &credit_hours[c]);

		if (credit_hours[c] <= 0.00 || credit_hours[c] >= 5.00) {
			printf("========Invalid credit hours for subject %d=======\n", c + 1);
			c--; // re-enter credit hours
		}
		else {
			semesterCredit_hours += credit_hours[c];
		}
	}

	allSemCreditHours += semesterCredit_hours;
	printf("\nTotal Credit Hours in current semester : %.2f", semesterCredit_hours);
	printf("\nTotal Credit Hours in all semester :%.2f\n", allSemCreditHours);


	//QUALITY POINT 
	printf("\n\t=====QUALITY POINT=====\n\n");
	for (int c = 0; c < subject; c++) {
		float courseQualityPt = (float)point[c] * credit_hours[c];
		printf("\tQUALITY POINT for %s :%.2f\n", course_codes[c], courseQualityPt);
		semesterQuality_Point += courseQualityPt;
	}
	printf("\nSemester Quality Point :%.2f\n", semesterQuality_Point);
	allsemQuality_point += semesterQuality_Point;
	printf("Total Quality point in all semester:%.2f\n", allsemQuality_point);


	// GPA/CGPA  RESULT 
	GPA = (float)semesterQuality_Point / semesterCredit_hours;
	CGPA = (float)allsemQuality_point / allSemCreditHours;
	printf("\n \t======Result=========\n");
	printf("\t|Student GPA is %.2f |\n", GPA);
	printf("\t|Student CGPA is %.2f|\n", CGPA);
	printf(" \t ======================\n");

}

void studentMode() {
	printf("\n");
	printf("%-14s%-20s\n", " ", "=========================");
	printf("%-15s%-20s\n", " ", "KOLEJ PASAR STUDENT MODE");
	printf("%-14s%-20s\n\n", " ", "=========================");

	printf("Enter your student ID: ");
	scanf("%s", studentID);

	printf("Welcome, Student %s!\n", name);
	printf("\n");
	printf("\t=====================YOUR RESULT===================\n");
	printf("\t%-18s \t%-11s \t%-11s\n", "Student Name", "GPA", "CGPA");
	printf("\t===================================================\n");
	printf("\t%-18s \t%-11.2lf \t%-11.2lf\n", name, GPA, CGPA);

	if (allSemCreditHours >= 21) {
		printf("\n\t-------------------------------------------------\n");
		printf(" \t\tCONGRATULATIONS! YOU HAVE GRADUATED!\n");
	}
	else if (allSemCreditHours < 21) {
		printf("\n\t-------------------------------------------------\n");
		printf("\t\tSORRY , YOU MUST FULFILL 21 CREDIT HOURS TO GRADUATED\n");
	}


	if (CGPA >= deansListCriteria) {
		printf("\tCongratulations! You made it to the Dean's List!\n");
		printf("\t-------------------------------------------------\n");
	}
	else if (CGPA >= honorsListCriteria) {
		printf("\tCongratulations! You made it to the Honors List!\n");
		printf("\t-------------------------------------------------\n");
	}
	else {
		printf("\t\tKeep up the good work!\n");
		printf("\t-------------------------------------------------\n");
	}
	studentAcademic_Advise();

}

void studentAcademic_Advise() {
	int option;
	printf("\n");
	printf("Would you need Academic Advise ? (Y = Yes , N=NO)\n");
	printf("PLEASE ENTER : ");
	getchar();
	scanf("%c", &yes_no);

	if (toupper(yes_no == 'Y')) {
		system("cls");
		printf("--------------------------------------\n");
		printf("|Options:                             |\n");
		printf("|1. View Available Courses            |\n");
		printf("|2. Add a Course to Your Schedule     |\n");
		printf("|3. Exit                              |\n");
		printf("--------------------------------------\n");
		printf("Enter Option you select:");
		scanf("%d", &option);

		if (option == 1) {
			struct Course {
				char code[10];
				char title[50];
				int credits;
			};

			struct Course courses[MAX_SUBJECTS] = {
				{"CSCI1001", "Introduction to Computer Science", 3},
				{"MATH2501", "Calculus I", 4},
				{"AACS7882","Introduction to Information Technology",3},
				{"AAMS4855","Web Design and Develop",3},
				{"FINC4856","Introduction to Financial",3},
				{"BAIT2083","Information Assurance and Security",3},
				{"BAIT3023","Information Systems Implementation",3},
				{"LOS84584","Logistics Information Systems",3},
				{"AMIS1003","Introduction to Cybersecurity",3},
			};

			printf("\nAvailable Courses:\n");
			printf("-------------------------------------------------------------------------------\n");
			printf("%-15s %-50s %-8s\n", "Course Code", "Subject", "Credits");
			printf("-------------------------------------------------------------------------------\n");
			for (int i = 0; i < sizeof(courses) / sizeof(courses[0]); i++) {
				printf("%-15s %-50s %-8d\n", courses[i].code, courses[i].title, courses[i].credits);
			}

			additionalSubject();
		}
		else if (option == 2) {
			additionalSubject();
		}
		else {
			system("cls");
			main();
		}
	}
}
void additionalSubject()
{
	char code[MAX_SUBJECTS][10]; // Array to store course codes for additional subjects
	int numAdditionalSubjects = 0; // Variable to keep track of the number of additional subjects

	// Loop to add additional subjects
	do {
		if (numAdditionalSubjects >= MAX_SUBJECTS) {
			printf("Your course schedule is full. You cannot add more courses.\n");
			break;
		}

		printf("Enter the course code for an additional subject: ");
		scanf("%s", code[numAdditionalSubjects]);
		printf("Course %s is added\n", code[numAdditionalSubjects]); // Display the added course code
		printf("\n");

		numAdditionalSubjects++;

		printf("Do you want to add another additional subject? (Y=YES, N=NO): ");
		scanf(" %c", &yes_no);
	} while (toupper(yes_no) == 'Y');

	// Display the list of additional subjects
	if (numAdditionalSubjects > 0) {
		system("cls");
		printf("\n");
		printf("\t\t\t============================\n");
		printf("\t\t\t\tADDITIONAL SUBJECTS\n");
		printf("\t\t\t============================\n");
		printf("\t\t\t\tCourse Code\n");
		printf("\t\t\t-----------------------------\n");
		for (int i = 0; i < numAdditionalSubjects; i++) {
			printf("\t\t\t%-15s\n", code[i]);
		}
	}
}





int main() {
	int mode = 0;
	char yes_no;

	logo(); //call function logo 

	do {

		//Select Mode 
		int mode;
		printf("\n------------------------------------------\n");
		printf("|          Please Select a Mode          |\n");
		printf("|1. STAFF                                |\n");
		printf("|2. STUDENT                              |\n");
		printf("|3. Method of Calculation GPA / CGPA     |\n");
		printf("|4. EXIT                                 |\n");
		printf("------------------------------------------\n");
		printf("Enter Mode you select:");
		scanf("%d", &mode);
		rewind(stdin);
		printf("\n");

		//STAFF MODE
		if (mode == 1) {
			system("cls");
			authenticateStaff();
			system("cls");
			printf("----------------------Staff ID authenticated----------------");
			printf("\n\n");
			printf("%-14s%-20s\n", " ", "=====================================");
			printf("%-15s%-20s\n", " ", "KOLEJ PASAR STAFF ADMINISTRATOR MODE");
			printf("%-14s%-20s\n\n", " ", "=====================================");
			staffMode();
		}
		//STUDENT MODE 
		else if (mode == 2) {
			system("cls");
			studentMode();

			//SELECTION FOR USING SYSTEM
			printf("\n\nWOULD YOU WANT CONTINUE OUR SYSTEM? (Y=YES, N=NO)\n");
			printf("-------------------------------------------------------\n");
			printf("| YES = GO BACK TO MENU  ||  NO = EXIT FROM OUR SYSTEM |\n");
			printf("-------------------------------------------------------\n");
			printf("PLEASE ENTER : ");
			getchar();
			scanf("%c", &yes_no);

			if (toupper(yes_no == 'N')) {
				printf("%-14s%-20s\n", " ", "=============================================");
				printf("%-15s%-20s\n", " ", "THANK YOU FOR USING OUR GPA/CGPA CALCULATOR");
				printf("%-14s%-20s\n\n", " ", "============================================\n");
				return 0;
			}

			else {
				system("cls");
				staffMode();
			}
		}

		//METHOD OF CALCULATION 
		else if (mode == 3) {
			printf("%-14s%-20s\n", " ", "=============================================");
			printf("%-15s%-20s\n", " ", "   METHOD OF USING CALCULATION GPA/CGPA");
			printf("%-14s%-20s\n\n", " ", "============================================\n");

			printf("GPA (Grade Point Average) Calculation:\n");
			printf("GPA is calculated by dividing the total quality points by the total credit hours.\n");
			printf("Quality Points are calculated based on the grades you earn in each course.\n");
			printf("Here's how you can calculate your GPA for a semester:\n");
			printf("1. Multiply the grade points for each course by the credit hours for that course.\n");
			printf("2. Add up all the quality points from step 1.\n");
			printf("3. Divide the total quality points by the total credit hours.\n");
			printf("4. That's your GPA for that semester!\n\n");

			printf("CGPA (Cumulative Grade Point Average) Calculation:\n");
			printf("CGPA is the overall GPA that considers your entire academic record.\n");
			printf("To calculate CGPA, you sum the quality points for all semesters and divide by\n");
			printf("the total credit hours from all semesters.\n");
			printf("Here's how you can calculate your CGPA:\n");
			printf("1. Sum the quality points from all semesters.\n");
			printf("2. Sum the total credit hours from all semesters.\n");
			printf("3. Divide the total quality points by the total credit hours.\n");
			printf("4. That's your CGPA!\n");
			printf("\n");
			printf("Dean's List Criteria:\n");
			printf("To qualify for the Dean's List, a student must typically have a GPA of 3.5 or higher\n");
			printf("and meet other specific academic requirements set by the institution.\n\n");

			printf("Honors List Criteria:\n");
			printf("The Honors List recognizes students with exceptionally high academic achievement.\n");
			printf("Specific criteria may vary, but it often requires a higher GPA than the Dean's List,\n");
			printf("clean academic record, and full-time enrollment status. Check with your institution\n");
			printf("for exact requirements.\n\n");

			//SELECTION FOR USING SYSTEM
			printf("\n\nWOULD YOU WANT CONTINUE OUR SYSTEM? (Y=YES, N=NO)\n");
			printf("-------------------------------------------------------\n");
			printf("| YES = GO BACK TO MENU  ||  NO = EXIT FROM OUR SYSTEM |\n");
			printf("-------------------------------------------------------\n");
			printf("PLEASE ENTER : ");
			getchar();
			scanf("%c", &yes_no);

			if (toupper(yes_no) == 'N') {
				printf("%-14s%-20s\n", " ", "=============================================");
				printf("%-15s%-20s\n", " ", "THANK YOU FOR USING OUR GPA/CGPA CALCULATOR");
				printf("%-14s%-20s\n\n", " ", "============================================\n");
				return 0;
			}
			else {
				system("cls");
			}

		}

		//EXIT 
		else if (mode == 4) {
			printf("%-14s%-20s\n", " ", "=============================================");
			printf("%-15s%-20s\n", " ", "THANK YOU FOR USING OUR GPA/CGPA CALCULATOR");
			printf("%-14s%-20s\n\n", " ", "============================================\n");
			return 0;
		}


		else {
			printf("Invalid Option");
		}

	} while (mode != 4); //USERS WILL BE EXIT FROM THIS SYSTEM 
}