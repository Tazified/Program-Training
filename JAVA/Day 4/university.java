import java.util.ArrayList;
import java.util.List;

class Person {
    protected String name;
    protected int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}


class Student extends Person {
    private int studentId;

    public Student(String name, int age, int studentId) {
        super(name, age);
        this.studentId = studentId;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Student ID: " + studentId);
    }
}


class Professor extends Person {
    private String employeeId;

    public Professor(String name, int age, String employeeId) {
        super(name, age);
        this.employeeId = employeeId;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Employee ID: " + employeeId);
    }
}


class Course {
    private String courseName;
    private List<Course> prerequisites;
    private List<Student> enrolledStudents;

    public Course(String courseName) {
        this.courseName = courseName;
        this.prerequisites = new ArrayList<>();
        this.enrolledStudents = new ArrayList<>();
    }

    public void addPrerequisite(Course prerequisite) {
        prerequisites.add(prerequisite);
    }

    public void enrollStudent(Student student) {
        if (hasCompletedPrerequisites(student)) {
            enrolledStudents.add(student);
            System.out.println(student.name + " enrolled in " + courseName);
        } else {
            System.out.println(student.name + " cannot enroll in " + courseName + ". Prerequisites not met.");
        }
    }

    private boolean hasCompletedPrerequisites(Student student) {
        for (Course prerequisite : prerequisites) {
            boolean hasEnrolled = prerequisite.enrolledStudents.contains(student);
            if (!hasEnrolled) {
                return false;
            }
        }
        return true;
    }

    public void displayEnrolledStudents() {
        System.out.println("Enrolled students in " + courseName + ":");
        for (Student student : enrolledStudents) {
            student.displayInfo();
            System.out.println();
        }
    }
}


public class UniversityEnrollmentSystem {
    public static void main(String[] args) {
        
        Student student1 = new Student("Alice", 20, 101);
        Student student2 = new Student("Bob", 22, 102);
        Professor professor1 = new Professor("Dr. Smith", 45, "P001");

        Course mathCourse = new Course("Mathematics");
        Course physicsCourse = new Course("Physics");

        mathCourse.addPrerequisite(physicsCourse);

        mathCourse.enrollStudent(student1);
        mathCourse.enrollStudent(student2);
        physicsCourse.enrollStudent(student1);

        mathCourse.displayEnrolledStudents();
        physicsCourse.displayEnrolledStudents();
    }
}
