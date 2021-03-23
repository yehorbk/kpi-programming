package com.streamflowsolutions.streamflow.service.impl;

import com.streamflowsolutions.streamflow.dto.VideoDto;
import com.streamflowsolutions.streamflow.entity.Video;
import com.streamflowsolutions.streamflow.exception.exceptions.NullEntityReferenceException;
import com.streamflowsolutions.streamflow.exception.exceptions.StreamflowEntityNotFoundException;
import com.streamflowsolutions.streamflow.repository.VideoRepository;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mockito;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit.jupiter.SpringExtension;

@ExtendWith(SpringExtension.class)
@SpringBootTest
public class VideoServiceImplTest {
    
    @Autowired
    VideoServiceImpl videoService;
    
    @Autowired
    ModelMapper modelMapper;
    
    @MockBean
    VideoRepository videoRepository;
    
    private static final Video VIDEO = new Video();
    private static final long VIDEO_ID = 1;
    
    @BeforeEach
    public void setUp() {
        VIDEO.setTitle("some_video");
        VIDEO.setDescription("description");
        VIDEO.setDate_of_publication("date");
        VIDEO.setAuthor(new User());
        VIDEO.setOPreview_src("src");
        Mockito.when(videoRepository.findById(VIDEO_ID))
                .thenReturn(Optional.of(VIDEO));
    }
    
    @Test
    public void testCreateVideo() {
        Mockito.when(this.videoRepository.save(VIDEO)).thenReturn(VIDEO);
        VideoDto actual = this.modelMapper.map(VIDEO, VideoDto.class);
        Assertions.assertEquals(VIDEO, this.videoService.create(actual));
    }
    
    @Test
    public void testCreateNullVideo() {
        Assertions.assertThrows(NullEntityReferenceException.class,
                () -> this.videoService.create(null));
    }
    
    @Test
    public void testReadByIdVideo() {
        Assertions.assertEquals(VIDEO, this.videoService.readById(VIDEO_ID));
    }
    
    @Test
    public void testUpdateNullVideo() {
        Assertions.assertThrows(NullEntityReferenceException.class,
                () -> this.videoService.update(null));
    }
    
    @Test
    public void testUpdateNotExistVideo() {
        VideoDto actual = this.modelMapper.map(VIDEO, VideoDto.class);
        Assertions.assertThrows(StreamflowEntityNotFoundException.class,
                () -> this.videoService.update(actual));
    }
    
    @Test
    public void testDeleteVideo() {
        Mockito.doNothing().when(this.videoRepository).delete(VIDEO);
        this.videoService.delete(VIDEO_ID);
        Mockito.verify(this.videoRepository, Mockito.times(1)).delete(VIDEO);
    }
    
    @Test
    public void testDeleteNotExistVideo() {
        Assertions.assertThrows(StreamflowEntityNotFoundException.class,
                () -> this.videoService.delete(0));
    }
    
    @Test
    public void testGetAllVideos() {
        List<Video> videos = new ArrayList<>();
        videos.add(VIDEO);
        Mockito.when(this.videoRepository.findAll()).thenReturn(videos);
        Assertions.assertEquals(1, this.videoService.getAll().size());
    }
    
    @Test
    public void testGetAllVideosWhenEmpty() {
        Assertions.assertEquals(0, this.videoService.getAll().size());
    }
    
}
