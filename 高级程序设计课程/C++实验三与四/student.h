#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
	private:
		string id;
		string name;
		int age;
		char gender;
		int type;				//类型：1->四门课，2->5门课
		float* scores;
		float average;
		bool hasFailed;

	public:
		//构造函数
		Student();
		Student(string i, string n, int a, char g, int t);		
		//析构函数
		~Student();		
		//输入输出
		void input();
		void inputScores();
		void show();
		void showSimple(int rank);
		//计算
		void CalculateAverage();
		void CalculateAverage(bool show);
		void check();
		//修改和查询
		void modify();
		bool matchId(string searchId);
		bool matchName(string searchName);
		//获取信息
		string getId() { return id; }
		string getName() { return name; }
		char getGender() { return gender; }
		float getAverage() { return average; }
		int getType() { return type; }
		float getScore(int i);
		bool getHasFailed() const { return hasFailed; }
		static void courceStats(Student* students[], int n);
};


#endif
