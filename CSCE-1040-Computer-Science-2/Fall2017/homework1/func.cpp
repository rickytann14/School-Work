#include "prgm.h"


void addstudents(studs * ppl){
	int id;
	char buff[80];
	
	stud *temp;//temp ptr

	//allcating memory?
	temp = (stud *) malloc(sizeof(stud));

	//Grabs student ID
	cout << "Enter studnet ID: ";
	scanf("%d%*c", &(temp -> stud_id));

	//Grab student name
	cout << "Enter student name: ";
	fgets(temp -> stu_name, 80, stdin);

	//set temp pts equal to NULL
	temp -> next = NULL;

	//set head, tail ptr = to temp ptr
	if(ppl -> stu_cnt == 0){
		ppl -> st_linkhead = ppl -> st_linktail = temp;
	}
	
	else{
		ppl -> st_linktail -> next = temp;
		ppl -> st_linktail = temp;
	}

	ppl -> stu_cnt+=1;
}

void addclasses(cors * schol){
	int id;
	char buff[80];

	cor *temp;

	temp = (cor *) malloc(sizeof(cor));

	cout << "Enter course ID: ";
	scanf("%d%*c", &(temp -> cur_id));

	cout << "Enter course name: ";
	fgets(temp -> cur_name, 80, stdin);

	temp -> next = NULL;

	if(schol -> cl_cnt ==0){
		schol -> cl_linkhead = schol -> cl_linktail = temp;
	}
	else{ 
		schol -> cl_linktail -> next = temp;
		schol -> cl_linktail = temp;
	}
	schol -> cl_cnt += 1;
}

void cleanup_stud(studs *enrol){
	stud *temp;
	
	temp = enrol -> st_linkhead;

	while(temp != NULL){
		stud *temp2;
		temp2 = temp -> next;
		free(temp);
		temp = temp2;
	}
}

void classprint(cors *schol){
	cor *temp;//creates temp ptr

	//set temp equal to head
	temp = schol -> cl_linkhead;
	//print everything untill reaching null
	while(temp != NULL){
		cor *temp2;//creats a second temp ptr
		temp2 = temp -> next;
		cout << "Course ID: " << temp -> cur_id << " Course Name: " << temp -> cur_name << endl;
		temp = temp2;
	}
}

void student_print(studs *ppl){
	stud *temp;//creates temp ptr

	//set ptr equal to headnode 
	temp = ppl -> st_linkhead;

	//print everything till you reach null
	while(temp != NULL){
		stud *temp2; //second temp ptr
		temp2 = temp -> next;//temp2 now equals the next ptr

		cout << "Student ID: " << temp -> stud_id << "Student Name: " << temp -> stu_name << endl;
		temp = temp2;//makes the temp ptr equal to next 
	}
}

void cleanup_course(cors *enrol){
	cor *temp;

	temp = enrol -> cl_linkhead;

	while(temp != NULL){
		cor *temp2;
		temp2 = temp -> next;
		free(temp);
		temp = temp2;
	}
}

void studtoclass(enrolls *atten){
	enroll *temp;

	temp = (enroll*) malloc(sizeof(enroll));

	cout << "Enter new enrollment ID: ";
	scanf("%d%*c", &(temp -> enroll_id));

	cout << "Enter student ID: ";
	scanf("%d%*c", &(temp -> stud_loc));

	cout <<"Enter course ID: ";
	scanf("%d%*c", &(temp -> cor_loc));

	temp -> next = NULL;

	if(atten -> roll_cnt == 0){
		atten -> enr_linkhead = atten -> enr_linktail = temp;
	}
	else{
		atten -> enr_linktail -> next = temp;
		atten -> enr_linktail = temp;
	}
	atten -> roll_cnt += 1;
}

void cleanup_enrol(enrolls *atten){
	enroll *temp;

	temp = atten -> enr_linkhead;
	while(temp != NULL){
		enroll *temp2;
		temp2 = temp -> next;
		free(temp);
		temp = temp2;
	}
}

void studinclass(enrolls *atten){
	enroll *temp;

	temp = atten -> enr_linkhead;

	while(temp != NULL){
		enroll *temp2;
		temp2 = temp -> next;
		cout << "student ID: " << temp -> stud_loc << "Course ID: " << temp -> cor_loc << endl;
		temp = temp2;
	}
}

void studgrade(enrolls *atten){
	enroll *temp;
	int studid, corid;
	int i,x;//counters
	temp= atten -> enr_linkhead;

	//Enter ID num of student
	cout <<"Enter student ID: " ;
	scanf("%d%*c", &studid);
	cout << endl;

	//Enter ID num for course
	cout <<"Enter course ID: ";
	scanf("%d%*c", &corid);
	cout << endl;

	cout << "Enter number of grades: ";
	scanf("%d%*c", &x);
	
	while(temp != NULL){
		enroll *temp2;
		temp2 = temp -> next;

		if((studid == temp -> stud_loc) && (corid == temp -> cor_loc) ){
			for(i=1; i<=x; i++){
				cout << "Enter grade #" << i << endl;
				scanf("%d%*c", &(temp -> grade[i]));
				atten -> grad_cnt += 1;
			}
		}
		temp = temp2;
	}
		//cout << "Student ID: " << studid << endl;
		//cout << "Course ID: " << corid << endl;
}

void studgradprint(enrolls *atten){
	enroll *temp;
	int corid, studid;
	int i,x; //counters

	temp = atten -> enr_linkhead;

	 //Enter ID num of student
        cout <<"Enter student ID: " ;
        scanf("%d%*c", &studid);
        cout << endl;

        //Enter ID num for course
        cout <<"Enter course ID: ";
        scanf("%d%*c", &corid);
        cout << endl;

	//traverse thur link list
	while(temp != NULL){
		enroll *temp2;
		temp2 = temp -> next;
		//if ID numbers match print out list of grades
		 if((studid == temp -> stud_loc) && (corid == temp -> cor_loc) ){

			cout <<"Student ID: " << studid << endl;

                        for(i=1; i<=(atten -> grad_cnt); i++){
				printf("Grade%2d: %3d\n", i, temp -> grade[i]);
			}
		}
		temp = temp2;
	}

}

void studavg(enrolls *atten){
	enroll *temp;
	int studid, corid;
	int i, x,avg, sum = 0;

	temp = atten -> enr_linkhead;

	//Enter ID num of student
        cout <<"Enter student ID: " ;
        scanf("%d%*c", &studid);
        cout << endl;

        //Enter ID num for course
        cout <<"Enter course ID: ";
        scanf("%d%*c", &corid);
        cout << endl;	

	//traverse thru link list
	while(temp != NULL){
		enroll *temp2;
		temp2 = temp -> next;

		cout <<"Student ID: " << studid << endl;

		//if numbers match calculate average
		if((studid == temp -> stud_loc) && (corid == temp -> cor_loc)){
			for(i=1;i <= (atten ->grad_cnt);i++){
				sum = (temp -> grade[i]) + sum;
			}
			avg = sum/(atten -> grad_cnt);
			(atten -> studavg) = avg;
		}
		temp = temp2;
	}
}
