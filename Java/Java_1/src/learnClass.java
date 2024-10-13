class Student {
    String name;
    int age;
    int grade;
    Student(){
    name = "sarun";
    age = 20;
    grade = 14;
    }
    Student(String name, int age, int grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
        System.out.printf("student\nname : %s\nage : %d\ngrade : %d\n", name, age, grade);
    }
}

public class learnClass {
    public static void main(String[] args) {
        @SuppressWarnings("unused")
        Student student = new Student("sarun", 19, 14);
    }
}
