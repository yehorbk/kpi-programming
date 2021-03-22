package com.streamflowsolutions.streamflow.service.impl;

import com.streamflowsolutions.streamflow.dto.VideoDto;
import com.streamflowsolutions.streamflow.entity.Video;
import com.streamflowsolutions.streamflow.repository.VideoRepository;
import com.streamflowsolutions.streamflow.service.VideoService;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import javax.persistence.EntityNotFoundException;
import org.springframework.stereotype.Service;

@Service
public class VideoServiceImpl implements VideoService {

    private VideoRepository videoRepository;

    public VideoServiceImpl(VideoRepository videoRepository) {
        this.videoRepository = videoRepository;
    }

    @Override
    public Video create(VideoDto videoDto) {
        try {
            Video video = new Video();
            video.setTitle(video.getTitle());
            video.setDescription(video.getDescription());
            video.setDate_of_publication(video.getDate_of_publication());
            video.setAuthor(video.getAuthor());
            video.setPreview_src(video.getPreview_src());
            return this.videoRepository.save(video);
        } catch (IllegalStateException e) {
            throw new NullPointerException("Video cannot be 'null'");
        }
    }

    @Override
    public Video readById(long id) {
        Optional<Video> optional = this.videoRepository.findById(id);
        if (optional.isPresent()) {
            return optional.get();
        }
        throw new EntityNotFoundException("Video with id=" + id + " not found");
    }

    @Override
    public Video update(VideoDto videoDto) {
        if (videoDto != null) {
            Video oldVideo = this.readById(videoDto.getId());
            oldVideo.setTitle(videoDto.getTitle());
            oldVideo.setDescription(videoDto.getDescription());
            oldVideo.setAuthor(videoDto.getAuthor());
            oldVideo.setDate_of_publication(videoDto.getDate_of_publication());
            oldVideo.setPreview_src(videoDto.getPreview_src());
            if (oldVideo != null) {
                return this.videoRepository.save(oldVideo);
            }
        }
        throw new NullPointerException("Video cannot be 'null'");
    }

    @Override
    public void delete(long id) {
        Video video = this.readById(id);
        if (video != null) {
            videoRepository.delete(video);
        } else {
            throw new EntityNotFoundException(
                    "Video with id=" + id + " not found"
            );
        }
    }

    @Override
    public List<Video> getAll() {
        List<Video> videos = this.videoRepository.findAll();
        return videos.isEmpty() ? new ArrayList<>() : videos;
    }

}
