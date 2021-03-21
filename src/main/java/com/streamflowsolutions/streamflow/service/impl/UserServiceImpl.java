package com.streamflowsolutions.streamflow.service.impl;

import com.streamflowsolutions.streamflow.entity.User;
import com.streamflowsolutions.streamflow.repository.UserRepository;
import com.streamflowsolutions.streamflow.service.UserService;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import javax.persistence.EntityNotFoundException;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService {
    
    private UserRepository userRepository;

    public UserServiceImpl(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @Override
    public User create(User user) {
        try {
            return this.userRepository.save(user);
        } catch (IllegalStateException e) {
            throw new NullPointerException("User cannot be 'null'"); // TODO: implement special exception for it (NullEntityReferenceException)
        }
    }

    @Override
    public User readById(long id) {
        Optional<User> optional = this.userRepository.findById(id);
        if (optional.isPresent()) {
            return optional.get();
        }
        throw new EntityNotFoundException("User with id=" + id + " not found"); // TODO: implement special wrapper to pass name and id
    }

    @Override
    public User update(User user) {
        if (user != null) {
            User oldUser = this.readById(user.getId());
            if (oldUser != null) {
                return this.userRepository.save(user);
            }
        }
        throw new NullPointerException("User cannot be 'null'"); // TODO: implement special exception for it (NullEntityReferenceException)
    }

    @Override
    public void delete(long id) {
        User user = this.readById(id);
        if (user != null) {
            userRepository.delete(user);
        } else {
            throw new EntityNotFoundException(
                    "User with id=" + id + " not found"
            ); // TODO: implement special wrapper to pass name and id
        }
    }

    @Override
    public List<User> getAll() {
        List<User> users = this.userRepository.findAll();
        return users.isEmpty() ? new ArrayList<>() : users;
    }
    
}
