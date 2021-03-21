package com.streamflowsolutions.streamflow.service;

import com.streamflowsolutions.streamflow.entity.User;
import java.util.List;

public interface UserService {
    
    User create(User user);
    User readById(long id);
    User update(User user);
    void delete(long id);
    List<User> getAll();
    
}
