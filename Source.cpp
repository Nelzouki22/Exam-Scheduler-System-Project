#include <iostream>
#include <vector>
#include <string>

struct Course {
    int id;
    std::string name;
    int students;
};

struct Exam {
    Course course;
    std::string timeslot;
};

class ExamScheduler {
private:
    std::vector<Course> courses;
    std::vector<Exam> exams;

public:
    void addCourse(int id, const std::string& name, int students) {
        courses.push_back({ id, name, students });
    }

    void scheduleExams() {
        const std::vector<std::string> timeslots = { "9:00-11:00", "11:00-1:00", "2:00-4:00", "4:00-6:00" };
        for (size_t i = 0; i < courses.size(); ++i) {
            exams.push_back({ courses[i], timeslots[i % timeslots.size()] });
        }
    }

    void printSchedule() const {
        std::cout << "Exam Schedule:\n";
        for (const auto& exam : exams) {
            std::cout << "Course ID: " << exam.course.id
                << ", Course Name: " << exam.course.name
                << ", Students: " << exam.course.students
                << ", Timeslot: " << exam.timeslot << "\n";
        }
    }
};

int main() {
    ExamScheduler scheduler;

    // Adding sample courses
    scheduler.addCourse(1, "Math", 30);
    scheduler.addCourse(2, "Physics", 25);
    scheduler.addCourse(3, "Chemistry", 20);
    scheduler.addCourse(4, "Biology", 15);

    // Schedule exams
    scheduler.scheduleExams();

    // Print the exam schedule
    scheduler.printSchedule();

    return 0;
}
