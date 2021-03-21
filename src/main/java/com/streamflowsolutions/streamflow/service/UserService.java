package com.streamflowsolutions.streamflow.service;

import com.streamflowsolutions.streamflow.dto.UserDto;
import com.streamflowsolutions.streamflow.entity.User;
import java.util.List;

public interface UserService {
    
    User create(UserDto user);
    User readById(long id);
    User update(UserDto user);
    void delete(long id);
    List<User> getAll();
    
}
