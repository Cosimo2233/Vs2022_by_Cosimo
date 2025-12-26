#include <stdio.h>
#include <stdlib.h>
struct student{
    long num;
    char name[20];
    char sex;
    int age;
    float score;
};
int main(){
    int n,male_count = 0, female_count = 0;
    struct student* students;
    float total_score = 0, average_score = 0;
    do{
        printf("number of students(2<=n<=4): ");
        scanf_s("%d", &n);
        if (n < 2 || n > 4)
        {
            printf("Error\n");
        }
    } while (n < 2 || n > 4);
    students = (struct student*)malloc(n * sizeof(struct student));
    if (students == NULL){
        printf("Error!\n");
        return 1;
    }
    for (int i = 0; i < n; i++){
        printf("input student:\n");
        printf("\nstudent %d\n", i + 1);
        printf("num: ");
        scanf_s("%ld", &students[i].num);
        printf("name: ");
        scanf_s("%s", students[i].name, (unsigned)sizeof(students[i].name));
        printf("sex (M/F)/(m/f): ");
        scanf_s(" %c", &students[i].sex);
        printf("age: ");
        scanf_s("%d", &students[i].age);
        printf("score: ");
        scanf_s("%f", &students[i].score);
    }
    for (int i = 0; i < n; i++){
        if (students[i].sex == 'M' || students[i].sex == 'm'){
            male_count++;
        }
        else if (students[i].sex == 'F' || students[i].sex == 'f'){
            female_count++;
        }
    }
    for (int i = 0; i < n; i++){
        total_score += students[i].score;
    }
        average_score = total_score / n;
        printf("\nStudents'Information:\n");
        for (int i = 0; i < n; i++){
            printf("student[%d]:   num:%ld,name:%s,sex:%c,age:%d,score:%f\n", i + 1, students[i].num, 
                    students[i].name, students[i].sex, students[i].age, students[i].score);}
        printf("\n\n");
        printf("Number of male is %d;\n", male_count);
        printf("Number of female is %d;\n", female_count);
        printf("Average score is %f\n", average_score);
        printf("Students below averrage score:\n");
        for (int i = 0; i < n; i++){
            if (students[i].score < average_score){
                printf("Num:%ld   Name:%s   Sex:%c   Age:%d   Score:%f\n",
                        students[i].num, students[i].name, students[i].sex, students[i].age, students[i].score);}
        }
        free(students);
        return 0;
}

