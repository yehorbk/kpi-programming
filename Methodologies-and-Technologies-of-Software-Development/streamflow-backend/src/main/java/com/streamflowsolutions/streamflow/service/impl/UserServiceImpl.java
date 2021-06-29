package com.streamflowsolutions.streamflow.service.impl;

import com.streamflowsolutions.streamflow.dto.UserDto;
import com.streamflowsolutions.streamflow.entity.User;
import com.streamflowsolutions.streamflow.exception.exceptions.NullEntityReferenceException;
import com.streamflowsolutions.streamflow.exception.exceptions.StreamflowEntityNotFoundException;
import com.streamflowsolutions.streamflow.repository.UserRepository;
import com.streamflowsolutions.streamflow.service.UserService;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService {
    
    private UserRepository userRepository;

    public UserServiceImpl(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @Override
    public User create(UserDto userDto) {
        if (userDto != null) {
            User user = new User();
            user.setEmail(userDto.getEmail());
            user.setPassword(userDto.getPassword());
            user.setTag(userDto.getTag());
            user.setName(userDto.getName());
            user.setBio(userDto.getBio());
            user.setGender(userDto.getGender());
            user.setNationality(userDto.getNationality());
            user.setDateOfBirth(userDto.getDateOfBirth());
            return this.userRepository.save(user);
        }
        throw new NullEntityReferenceException("User");
    }

    @Override
    public User readById(long id) {
        Optional<User> optional = this.userRepository.findById(id);
        if (optional.isPresent()) {
            return optional.get();
        }
        throw new StreamflowEntityNotFoundException(
                    "User", "id", String.valueOf(id));
    }

    @Override
    public User update(UserDto userDto) {
        if (userDto != null) {
            User oldUser = this.readById(userDto.getId());
            oldUser.setPassword(userDto.getPassword());
            oldUser.setTag(userDto.getTag());
            oldUser.setName(userDto.getName());
            oldUser.setBio(userDto.getBio());
            oldUser.setGender(userDto.getGender());
            oldUser.setNationality(userDto.getNationality());
            oldUser.setDateOfBirth(userDto.getDateOfBirth());
            oldUser.setAvatarSrc(userDto.getAvatarSrc());
            if (oldUser != null) {
                return this.userRepository.save(oldUser);
            }
        }
        throw new NullEntityReferenceException("User");
    }

    @Override
    public void delete(long id) {
        User user = this.readById(id);
        if (user != null) {
            userRepository.delete(user);
        } else {
            throw new StreamflowEntityNotFoundException(
                    "User", "id", String.valueOf(id));
        }
    }

    @Override
    public List<User> getAll() {
        List<User> users = this.userRepository.findAll();
        return users.isEmpty() ? new ArrayList<>() : users;
    }
    
}
