package railway.train;

public class TrainEntity {
    private String name;
    private String source;
    private String destination;
    // Using Integer wrapper classes for counts
    private Integer seating;
    private Integer sleeper;
    private Integer ac;

    public TrainEntity(String name, String source, String destination, Integer seating, Integer sleeper, Integer ac) {
        this.name = name;
        this.source = source;
        this.destination = destination;
        this.seating = seating;
        this.sleeper = sleeper;
        this.ac = ac;
    }

    public String getName() { return name; }
    public String getSource() { return source; }
    public String getDestination() { return destination; }
    public Integer getSeating() { return seating; }
    public Integer getSleeper() { return sleeper; }
    public Integer getAc() { return ac; }

    public void displayTrain() {
        System.out.println("Train Name: " + name + " | Route: " + source + " -> " + destination +
                           " | Seating: " + seating + " | Sleeper: " + sleeper + " | AC: " + ac);
    }
}
