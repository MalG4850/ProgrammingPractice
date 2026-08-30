package railway.login;

public class LoginService {
    private User user;

    public LoginService(User user) {
        this.user = user;
    }

    public boolean verifyUser(String username, String password) {
        return user != null && 
               user.getUsername().equals(username) && 
               user.getPassword().equals(password);
    }

    public boolean login(String username, String password) {
        return verifyUser(username, password);
    }
}