/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2010, Robert Bosch LLC.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Robert Bosch nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************/

ros.visualization.VisualizationManager = Class.extend({
  init: function(canvas_name) {
    this.tf = null;
    this.node = null;
    this.canvas_name = canvas_name;
    this.scene_viewer = new ros.visualization.SceneViewer();
    this.marker_manager = new ros.visualization.MarkerManager(this);

    RightContext.initialize(canvas_name);    
    sglRegisterLoadedCanvas(canvas_name, this.scene_viewer, 25.0);
  },

  initialize: function(node, tf) {
    this.node = node;
    this.tf = tf;
    this.scene_viewer.tf = tf;
    this.scene_viewer.puppetInteractor.kinematicSrv = node.serviceClient("/get_pose");
    this.scene_viewer.puppetInteractor.releaseSrv = node.serviceClient("/release_pose");
    this.gl = this.scene_viewer.ui.gl;
    this.shader_manager = new ros.visualization.ShaderManager(this.gl);
    this.interactive_marker_manager = new ros.visualization.InteractiveMarkerManager(this);
  },
  
  removeVisualizationNode: function(vis_node) {
    this.scene_viewer.removeNode(vis_node);
  },

  addNode : function(node) {
    node.setVM(this);
    this.scene_viewer.addNode(node);
  },
  
  addCoordinateFrame: function(frame_id) {
    var scene_node = new ros.visualization.CoordinateFrameNode(this);
    scene_node.setFrame(frame_id);
    this.scene_viewer.addNode(scene_node);

    return scene_node;
  },
  
  addMarker: function(marker_topic) {
    this.marker_manager.subscribeMarker(marker_topic);
  },

  addInteractiveMarker: function(imarker_topic) {
    this.interactive_marker_manager.subscribeInteractiveMarker(imarker_topic);
  },
  
  addTF: function() {
    var tf_node = new ros.visualization.TFNode(this, this.tf);
    this.scene_viewer.addNode(tf_node);
    return tf_node;
  },
  
  addRobotModel: function(urdf_xml,alpha) {
    var robot_node = new ros.visualization.RobotNode(this, urdf_xml,alpha);
    robot_node.load();
    this.scene_viewer.addNodeWithoutLoading(robot_node);
    robot_node.setBoundingBoxEnable(true);
    return robot_node;
  },
	  
  addGrid: function(frame_id, size, resolution) {
    var scene_node = new ros.visualization.SceneNode(this);
    var grid_model = new ros.visualization.GridModel(this.gl, this.shader_manager, size,resolution);

    scene_node.setModel(grid_model);
    scene_node.setFrame(frame_id);

    this.scene_viewer.addNode(scene_node);
    return scene_node;
  },
  
  addVisualizationScene: function(scene_topic) {
    this.marker_manager.subscribeVisualizationScene(scene_topic);
  },

  addMap : function(frame_id,maptopic)
  {
    var scene_node = new ros.visualization.MapNode(this);
    this.node.subscribe(maptopic, function(msg) { scene_node.updateFromMessage(msg); });

    this.scene_viewer.addNode(scene_node);
    return scene_node;

  },
  
  addBox: function(frame_id) {
    var scene_node = new ros.visualization.SceneNode(this);
    var box_model = new ros.visualization.BoxModel(this.gl, this.shader_manager, 0.05);

    scene_node.setModel(box_model);
    scene_node.setFrame(frame_id);

    this.scene_viewer.addNode(scene_node);
    return scene_node;
  },

  addCollada : function(frame_id,src) {
    var scene_node = new ros.visualization.SceneNode(this);
    var uri = src.replace("package://","resources/");
    var scene = {frame:frame_id, url:uri, specular:[0.0,0.0,0.0,0.0], eye:[0.0,0.0,4.0], alpha:1.0}; 
    var collada_model = new ros.visualization.ColladaModel(this.gl, this.shader_manager,scene); 
    
    scene_node.setModel(collada_model);
    scene_node.setFrame(frame_id);

    this.scene_viewer.addNode(scene_node);

    return scene_node;
  },

  
  addSphere: function(frame_id) {
    var scene_node = new ros.visualization.SceneNode(this);
    var sphere_model = new ros.visualization.SphereModel(this.gl, this.shader_manager, 0.05, 10, 10);

    scene_node.setModel(sphere_model);
    scene_node.setFrame(frame_id);

    this.scene_viewer.addNode(scene_node);
    return scene_node;
  },
  
  addArrow: function(frame_id) {
    var scene_node = new ros.visualization.SceneNode(this);
    var arrow_model = new ros.visualization.ArrowModel(this.gl, this.shader_manager);

    scene_node.setModel(arrow_model);
    scene_node.setFrame(frame_id);
    this.scene_viewer.addNode(scene_node);
    return arrow_model;
  },
  
  addPointCloud: function(pointcloud) {
    var scene_node = new ros.visualization.SceneNode(this);
    var point_cloud_model = new ros.visualization.PointCloudModel(this.gl, this.shader_manager, pointcloud);


    scene_node.setModel(point_cloud_model);
    scene_node.setFrame(pointcloud.header.frame_id);
    this.scene_viewer.addNode(scene_node);
    return scene_node;
  },

  addPointCloud2: function(pointcloudtopic, frame_id) {
    var scene_node = new ros.visualization.SceneNode(this);
    var n = arguments.length;
    if(n > 1) {
    	scene_node.setFrame(frame_id);
    } 
    
    var point_cloud_model = new ros.visualization.PointCloud2Model(this.gl, this.shader_manager,this.scene_viewer,this.node,pointcloudtopic);
    
    scene_node.setModel(point_cloud_model);
    this.scene_viewer.addNode(scene_node);
    return scene_node;
  },                                                  
});
