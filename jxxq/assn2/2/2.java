/*
 * Java Xiaoxueqi - Assignment 2 - 2
 * Haoyu Zhao
 * All of the code in this problem are included in this file
 */

class TestClasses {
    public static void main(String[] args) {
        Man man = new Man("man", "nothing");
        SuperMan superman = new SuperMan("superman","nothing");
        Person pman = new Man("pman", "nothing");
        Person psman = new SuperMan("psman", "mothing");
        Man msMan = new SuperMan("msMan", "nothing");

        System.out.println("begin test the classes and the methods");
        System.out.println();

        System.out.println("man:");
        System.out.println(man.getName());
        System.out.println(man.getDescription());
        System.out.println(man.changeSomething());
        man.move();

        System.out.println();

        System.out.println("superman:");
        System.out.println(superman.getName());
        System.out.println(superman.getDescription());
        System.out.println(superman.changeSomething());
        superman.move();
        superman.fly();

        System.out.println();

        System.out.println("pman:");
        System.out.println(pman.getName());
        System.out.println(pman.getDescription());
        System.out.println(pman.changeSomething());
        //pman.move();
        //pman.fly();

        System.out.println();

        System.out.println("psman:");
        System.out.println(psman.getName());
        System.out.println(psman.getDescription());
        System.out.println(psman.changeSomething());
        //psman.move();
        //psman.fly();

        System.out.println();
        
        System.out.println("msman:");
        System.out.println(msMan.getName());
        System.out.println(msMan.getDescription());
        System.out.println(msMan.changeSomething());
        msMan.move();
        //msMan.fly();

    }
}       

class Man implements Person {
    //private instance variables
    private String name;
    private String description;
    private int count;

    //add a constructor with no parameter
    public Man() {
        this.name = "Newbie";
        this.description = "I'm a Newbie";
        this.count = 0;
    }

    public Man(String na, String de) {
        this.name = na;
        this.description = de;
        this.count = 0;
    }

    //implements the abstract method in the interface
    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public int changeSomething() {
        return this.count = this.count - 1;
    }

    //new method
    public void move() {
        System.out.println("I am moving...");
    }
}

class SuperMan extends Man {
    //cover the instance variable in the super class
    private int count;
    
    //constructor1, no parameters
    public SuperMan() {
        super("superMan", "I can fly");
        this.count = 0;
    }
    
    //constructor2, 2 parameters, Name and Description
    public SuperMan(String na, String de) {
        super(na, de);
        this.count = 0;
    }

    //overwrite the method
    public void move() {
        System.out.println("I am flying...");
    }

    //new method
    public void fly() {
        System.out.println("fly, I am a SuperMan");
    }

    //overwrite the method
    public int changeSomething() {
        return this.count = this.count + 1;
    }
}