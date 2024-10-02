#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<fstream>
using namespace std;

class Job {
public:
    string jobTitle;
    string companyName;
    int salary;
    int YearsOfExperience;
    string location;
    vector<string> jobRequirements;

    Job()
    {

    }

     void setJobTitle(string jobTitle)
    {
        this->jobTitle = jobTitle;
    }

    void setCompanyName(string companyName)
    {
        this->companyName = companyName;
    }

    void setSalary(int salary)
    {
        this->salary = salary;
    }

    void setLocation(string location)
    {
        this->location = location;
    }

    void setyearsOfExperience(int YearsOfExperience)
    {
        this->YearsOfExperience=YearsOfExperience;
    }

    void setJobRequirements(vector<string> jobRequirements)
    {
        this->jobRequirements=jobRequirements;
    }

    string getJobTitle()
    {
        return jobTitle;
    }

    string getCompanyName()
    {
        return companyName;
    }

    double getSalary() const
    {
        return salary;
    }

    string getLocation() const
    {
        return location;
    }

    int getyearsofexperience()
    {
        return YearsOfExperience;
    }

    vector<string> getJobRequirements()
    {
        return jobRequirements;
    }
};

class User
{
public:
    string name;
    int age;
    string gender;
    long long int phone_number;
    string address;
    string degree;
    string university;
    int programming_skill;
    int problem_solving_skill;
    int communication_skill;
    int graduation_year;
    string current_employer;
    string job_title;
    int teamwork_skill;
    string educationLevel;
    int yearsOfExperience;
    vector<string> skills;
    string location;
    string contactInfo;
    User()
{

}
     void setDetails()
    {

    //Personal details

    cout<<"\n";
    cout<<"Personal Details Section\n";
    cout<<"------------------------\n";
    cout<<"Please enter your name: ";
    getline(cin,name);

    cout << "Please enter your age: ";
    cin >> age;


    cout << "Please enter your gender: ";
    cin >> gender;


    cout << "Please enter your phone number: ";
    cin >> phone_number;


    cout << "Please enter your address: ";
    cin>>address;

    // Education

    cout<<"\n";

    cout<<"Higher Education Details Section\n";
    cout<<"--------------------------------\n";

    cout << "Please enter your highest degree earned: ";
    cin>>degree;


    cout << "Please enter the name of the university you attended: ";
    cin>>university;


    cout << "Please enter your graduation year: ";
    cin >> graduation_year;



    cout << "Please enter the name of your current or most recent employer: ";
    cin>> current_employer;


    cout << "Please enter your current or most recent job title: ";
    cin>>job_title;


    // Skills

    cout<< "\n";

    cout<<"Personal Skills Details Section\n";
    cout<<"-------------------------------\n";

    cout << "Please rate your proficiency (1-10) in the following skills:" << endl;

    cout<<"\n";

    cout << "Programming: ";
    cin >> programming_skill;


    cout << "Communication: ";
    cin >> communication_skill;


    cout << "Problem Solving: ";
    cin >> problem_solving_skill;


    cout << "Teamwork: ";
    cin >> teamwork_skill;

    }

    // More Details

    //cout<<"More Educational Details Section\n";
    //cout<<"-------------------------------\n";
    void setEducationLevel()
    {
        cout<<endl;
        cout<<"Please enter education level: ";
        cin>>educationLevel;
    }

    void setYearsOfExperience()
    {
        cout<<"Please enter years of experience: ";
        cin>>yearsOfExperience;
    }

    void setSkills()
    {
        int n;
        string str;
        cout<<"Please enter the number of skills = ";
        cin>>n;
        cout<<"Please enter skills: ";
        for(int i=0;i<n;i++)
        {
        cin>>str;
        skills.push_back(str);
        }
    }

    // other necessary Details


    void setLocation()
    {
        cout<<"Please enter location: "<<endl;
        cin>>location;
    }

    void setContactInfo()
    {
        cout<<"Please enter contact email: "<<endl;
        cin>>contactInfo;
    }

    string getName()
    {
        return name;
    }

    string getEducationLevel()
    {
        return educationLevel;
    }

    int getYearsOfExperience()
    {
        return yearsOfExperience;
    }

    vector<string> getSkills()
    {
        return skills;
    }

    string getLocation()
    {
        return location;
    }


};

class JobMatcher: public Job,public User
{
    public:
    vector<Job> jobs;
    JobMatcher()
    {

    }

    void addJob(Job job)
    {
        jobs.push_back(job);
    }

    void displayJobMatches(User user) const
     {
        cout << "Job Matches for " << user.getName() << ":" << endl;

        for (Job job : jobs)
            {
            bool isMatch = true;

            // Check education level requirement

            bool eduMatch = false;
            for (string req : job.getJobRequirements())
            {
                if (user.getEducationLevel().find(req)!=string::npos)
                {
                    eduMatch = true;
                    break;
                }
            }
            if (!eduMatch)
            {
                isMatch = false;
            }

            // Check work experience requirement

            if (user.getYearsOfExperience() < job.getyearsofexperience())
            {
                isMatch = false;
            }

            // Check skills requirement

            bool hasSkill = false;
            for(int i=0;i<jobRequirements.size();i++)
            {
                 string req=job.jobRequirements[i];
                for (int j=0;j<skills.size();j++)
                {
                    string skill=user.skills[i];
                    if (skill==req)
                    {
                        hasSkill = true;
                        break;
                    }
                }
            }


            // Check location requirement

            if (user.getLocation() != job.getLocation())
            {
                isMatch = false;
            }

            // Display job if all requirements are met

            if (isMatch)
            {
                cout << "Job Title: " << job.getJobTitle() << endl;
                cout << "Company Name: " << job.getCompanyName() << endl;
                cout << "Beginning Salary: " << job.getSalary() << endl;
            }
        }

     }
};

int main()
{
    for(int i = 1, k = 0; i <= 4; ++i, k = 0)
    {
        for(int space = 1; space <= 4-i; ++space)
        {
            cout <<"  ";
        }

        while(k != 2*i-1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }

    cout<<"WELCOME TO OUR JOB PLACEMENT PORTAL!!!!!!!"<<endl;

    for(int i = 4; i >= 1; --i)
    {
        for(int space = 0; space < 4-i; ++space)
            cout << "  ";

        for(int j = i; j <= 2*i-1; ++j)
            cout << "* ";

        for(int j = 0; j < i-1; ++j)
            cout << "* ";

        cout << endl;
    }

    cout<<"\n";

    cout<<"Input the following details to find the best suitable job for yourself"<<endl;
    cout<<"======================================================================"<<endl;


    // Create some jobs

    Job job1;
    job1.setCompanyName("Sony");
    job1.setJobRequirements({"BBA","sales"});
    job1.setJobTitle("Manager");
    job1.setLocation("lucknow");
    job1.setyearsOfExperience(2);
    job1.setSalary(50000);


    Job job2;
    job2.setCompanyName("Joseph school");
    job2.setJobRequirements({"BEd","teaching"});
    job2.setJobTitle("Math Teacher");
    job2.setyearsOfExperience(2);
    job2.setLocation("noida");
    job2.setSalary(20000);


    Job job3;
    job3.setCompanyName("Deloitte");
    job3.setJobRequirements({"BTech","Coding"});
    job3.setJobTitle("Software Developer");
    job3.setyearsOfExperience(4);
    job3.setLocation("Pune");
    job3.setSalary(80000);


    Job job4;
    job4.setCompanyName("BIBA");
    job4.setJobRequirements({"BDes","designing"});
    job4.setJobTitle("Fashion Designer");
    job4.setyearsOfExperience(3);
    job4.setLocation("Mumbai");
    job4.setSalary(60000);

    // Add jobs to the job matcher

    JobMatcher jobMatcher;
    jobMatcher.addJob(job1);
    jobMatcher.addJob(job2);
    jobMatcher.addJob(job3);
    jobMatcher.addJob(job4);

    // Create a user

    User user;
    user.setDetails();
    user.setEducationLevel();
    user.setLocation();
    user.setSkills();
    user.setContactInfo();
    user.setYearsOfExperience();

    // Find job matches for the user

    jobMatcher.displayJobMatches(user);

    string filename = "UserDetails.txt";
    ofstream outfile;
    outfile.open(filename);

     if (!outfile)
    {
        cout << "Error: could not open file " << filename << endl;
        return 1;
    }
  else

  {

    outfile << "Name: " << user.name << endl;
    outfile << "Age: " << user.age << endl;
    outfile << "Gender: " << user.gender << endl;
    outfile << "Phone Number: " << user.phone_number << endl;
    outfile << "Address: " << user.address << endl;
    outfile << "Highest Degree Earned: " <<user.degree << endl;
    outfile << "University Attended: " << user.university << endl;
    outfile << "Graduation Year: " << user.graduation_year << endl;
    outfile << "Years of Work Experience: " << user.yearsOfExperience << endl;
    outfile << "Current or Most Recent Employer: " << user.current_employer << endl;
    outfile << "Current or Most Recent Job Title: " << user.job_title << endl;
    outfile << "Programming Skill (1-10): " << user.programming_skill << endl;
    outfile << "Communication Skill (1-10): " << user.communication_skill << endl;
    outfile << "Problem Solving Skill (1-10): " << user.problem_solving_skill << endl;
  }
    outfile.close();                                   //closing the file

    cout<<"Information successfully saved in database!"<<endl;

    return 0;

}
