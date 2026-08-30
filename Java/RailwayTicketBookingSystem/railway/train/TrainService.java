package railway.train;

import java.util.ArrayList;
import java.util.List;

public class TrainService {
    private List<TrainEntity> trainList;

    public TrainService() {
        this.trainList = new ArrayList<>();
    }

    public void addTrain(TrainEntity train) {
        trainList.add(train);
    }

    public List<TrainEntity> getTrains() {
        return trainList;
    }

    public List<TrainEntity> searchTrain(String source, String destination) {
        List<TrainEntity> found = new ArrayList<>();
        for (TrainEntity train : trainList) {
            if (train.getSource().equalsIgnoreCase(source) && 
                train.getDestination().equalsIgnoreCase(destination)) {
                found.add(train);
            }
        }
        return found;
    }

    public void displayAllTrains() {
        for (TrainEntity train : trainList) {
            train.displayTrain();
        }
    }
}