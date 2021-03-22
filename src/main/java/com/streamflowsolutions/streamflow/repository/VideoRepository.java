package com.streamflowsolutions.streamflow.repository;

import com.streamflowsolutions.streamflow.entity.Video;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface VideoRepository extends JpaRepository<Video, Long> {

}