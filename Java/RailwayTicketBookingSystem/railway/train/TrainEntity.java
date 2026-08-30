package railway.train;

public class TrainEntity {
    private String name;
    private String source;
    private String destination;
    private Integer seating;
    private Integer sleeper;
    private Integer ac;

    public TrainEntity(String name, String source, String destination, 
                       Integer seating, Integer sleeper, Integer ac) {
        this.name = name;
        this.source = source;
        this.destination = destination;
        this.seating = seating;
        this.sleeper = sleeper;
        this.ac = ac;
    }

    public String getName() {
        return name;
    }

    public String getSource() {
        return source;
    }

    public String getDestination() {
        return destination;
    }

    public Integer getSeating() {
        return seating;
    }

    public Integer getSleeper() {
        return sleeper;
    }

    public Integer getAc() {
        return ac;
    }
    public void decrementSeating() {
        if (seating > 0) seating--;
    }

    public void decrementSleeper() {
        if (sleeper > 0) sleeper--;
    }

    public void decrementAc() {
        if (ac > 0) ac--;
    }

    public void displayTrain() {
        System.out.println("Train: " + name);
        System.out.println("Source: " + source + " -> Destination: " + destination);
        System.out.println("Available - Seating: " + seating + ", Sleeper: " + sleeper + ", AC: " + ac);
        System.out.println("-----------------------------------");
    }
}