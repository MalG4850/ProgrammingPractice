package railway.train;

import java.util.ArrayList;

public class TrainService {
    private ArrayList<TrainEntity> trainLists;

    public TrainService() {
        trainLists = new ArrayList<TrainEntity>();
        // Mock dataset
        addTrain(new TrainEntity("Express 101", "Pune", "Mumbai", 50, 30, 15));
        addTrain(new TrainEntity("Deccan Express", "Mumbai", "Pune", 40, 20, 10));
        addTrain(new TrainEntity("Goa SF Express", "Pune", "Goa", 60, 40, 20));
    }

    public void addTrain(TrainEntity train) {
        trainLists.add(train);
    }

    public ArrayList<TrainEntity> getTrains() {
        return trainLists;
    }

    public ArrayList<TrainEntity> searchTrain(String source, String destination) {
        ArrayList<TrainEntity> foundTrains = new ArrayList<TrainEntity>();
        for (int i = 0; i < trainLists.size(); i++) {
            TrainEntity t = trainLists.get(i);
            if (t.getSource().equalsIgnoreCase(source) && t.getDestination().equalsIgnoreCase(destination)) {
                foundTrains.add(t);
            }
        }
        return foundTrains;
    }

    public void displayAllTrains() {
        System.out.println("\n--- All Available Trains ---");
        for (int i = 0; i < trainLists.size(); i++) {
            System.out.print("[" + (i + 1) + "] ");
            trainLists.get(i).displayTrain();
        }
    }
}
