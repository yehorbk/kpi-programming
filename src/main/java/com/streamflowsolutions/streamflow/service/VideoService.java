package com.streamflowsolutions.streamflow.service;

import com.streamflowsolutions.streamflow.dto.VideoDto;
import com.streamflowsolutions.streamflow.entity.Video;
import java.util.List;

public interface VideoService {

    Video create(VideoDto video);
    Video readById(long id);
    Video update(VideoDto video);
    void delete(long id);
    List<Video> getAll();

}
