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

ros.visualization.ArrowModel = ros.visualization.Model.extend({
  init: function(gl, shader_manager) 
  {
    this._super(gl, shader_manager);
    this.prog = shader_manager.shaderPrograms[shader_manager.ShaderTypes.FLAT];
    this.renderer = new SglMeshGLRenderer(this.prog);
    this.scale = [3.0, 3.0, 1.0];
    this.name ="Arrow Model";
  },
   
  load: function (callback, scene_viewer)
  {  
    var arrow_vertices = [
      0.000000,0.040000,-0.800000,0.028284,0.028284,-0.800000,
      0.000000,0.000000,-1.000000,0.028284,0.028284,-0.800000,
      0.040000,0.000000,-0.800000,0.000000,0.000000,-1.000000,
      0.040000,0.000000,-0.800000,0.028284,-0.028284,-0.800000,
      0.000000,0.000000,-1.000000,0.028284,-0.028284,-0.800000,
      0.000000,-0.040000,-0.800000,0.000000,0.000000,-1.000000,
      0.000000,-0.040000,-0.800000,-0.028284,-0.028284,-0.800000,
      0.000000,0.000000,-1.000000,-0.028284,-0.028284,-0.800000,
      -0.040000,0.000000,-0.800000,0.000000,0.000000,-1.000000,
      -0.040000,0.000000,-0.800000,-0.028284,0.028284,-0.800000,
      0.000000,0.000000,-1.000000,-0.028284,0.028284,-0.800000,
      0.000000,0.040000,-0.800000,0.000000,0.000000,-1.000000,
      0.000000,0.010000,0.000000,0.007000,0.007000,0.000000,
      0.007000,0.007000,-0.800000,0.000000,0.010000,-0.800000,
      0.000000,-0.010000,0.000000,-0.007000,-0.007000,0.000000,
      -0.007000,-0.007000,-0.800000,0.000000,-0.010000,-0.800000,
      -0.007000,-0.007000,0.000000,-0.010000,0.000000,0.000000,
      -0.010000,0.000000,-0.800000,-0.007000,-0.007000,-0.800000,
      -0.010000,0.000000,0.000000,-0.007000,0.007000,0.000000,
      -0.007000,0.007000,-0.800000,-0.010000,0.000000,-0.800000,
      -0.007000,0.007000,0.000000,0.000000,0.010000,0.000000,
      0.000000,0.010000,-0.800000,-0.007000,0.007000,-0.800000,
      0.007000,0.007000,0.000000,0.010000,0.000000,0.000000,
      0.010000,0.000000,-0.800000,0.007000,0.007000,-0.800000,
      0.010000,0.000000,0.000000,0.007000,-0.007000,0.000000,
      0.007000,-0.007000,-0.800000,0.010000,0.000000,-0.800000,
      0.007000,-0.007000,0.000000,0.000000,-0.010000,0.000000,
      0.000000,-0.010000,-0.800000,0.007000,-0.007000,-0.800000,
      -0.007000,0.007000,-0.800000,-0.028284,0.028284,-0.800000,
      -0.040000,0.000000,-0.800000,-0.010000,0.000000,-0.800000,
      -0.010000,0.000000,-0.800000,-0.040000,0.000000,-0.800000,
      -0.028284,-0.028284,-0.800000,-0.007000,-0.007000,-0.800000,
      -0.007000,-0.007000,-0.800000,-0.028284,-0.028284,-0.800000,
      0.000000,-0.040000,-0.800000,0.000000,-0.010000,-0.800000,
      0.000000,-0.010000,-0.800000,0.000000,-0.040000,-0.800000,
      0.028284,-0.028284,-0.800000,0.007000,-0.007000,-0.800000,
      0.028284,-0.028284,-0.800000,0.040000,0.000000,-0.800000,
      0.010000,0.000000,-0.800000,0.007000,-0.007000,-0.800000,
      0.040000,0.000000,-0.800000,0.028284,0.028284,-0.800000,
      0.007000,0.007000,-0.800000,0.010000,0.000000,-0.800000,
      0.007000,0.007000,-0.800000,0.028284,0.028284,-0.800000,
      0.000000,0.040000,-0.800000,0.000000,0.010000,-0.800000,
      0.000000,0.010000,-0.800000,0.000000,0.040000,-0.800000,
      -0.028284,0.028284,-0.800000,-0.007000,0.007000,-0.800000
    ];

    var arrow_normals = [
      0.000000,0.980581,-0.196116,0.693375,0.693375,-0.196116,
      0.357407,0.862856,-0.357407,0.693375,0.693375,-0.196116,
      0.980581,0.000000,-0.196116,0.862856,0.357407,-0.357407,
      0.980581,0.000000,-0.196116,0.693375,-0.693375,-0.196116,
      0.862856,-0.357407,-0.357407,0.693375,-0.693375,-0.196116,
      0.000000,-0.980581,-0.196116,0.357407,-0.862856,-0.357407,
      0.000000,-0.980581,-0.196116,-0.693375,-0.693375,-0.196116,
      -0.357407,-0.862856,-0.357407,-0.693375,-0.693375,-0.196116,
      -0.980581,0.000000,-0.196116,-0.862856,-0.357407,-0.357407,
      -0.980581,0.000000,-0.196116,-0.693375,0.693375,-0.196116,
      -0.862856,0.357407,-0.357407,-0.693375,0.693375,-0.196116,
      0.000000,0.980581,-0.196116,-0.357407,0.862856,-0.357407,
      0.000000,1.000000,0.000000,0.707107,0.707107,0.000000,
      0.707107,0.707107,0.000000,0.000000,1.000000,0.000000,
      0.000000,-1.000000,0.000000,-0.707107,-0.707107,0.000000,
      -0.707107,-0.707107,0.000000,0.000000,-1.000000,0.000000,
      -0.707107,-0.707107,0.000000,-1.000000,0.000000,0.000000,
      -1.000000,0.000000,0.000000,-0.707107,-0.707107,0.000000,
      -1.000000,0.000000,0.000000,-0.707107,0.707107,0.000000,
      -0.707107,0.707107,0.000000,-1.000000,0.000000,0.000000,
      -0.707107,0.707107,0.000000,0.000000,1.000000,0.000000,
      0.000000,1.000000,0.000000,-0.707107,0.707107,0.000000,
      0.707107,0.707107,0.000000,1.000000,0.000000,0.000000,
      1.000000,0.000000,0.000000,0.707107,0.707107,0.000000,
      1.000000,0.000000,0.000000,0.707107,-0.707107,0.000000,
      0.707107,-0.707107,0.000000,1.000000,0.000000,0.000000,
      0.707107,-0.707107,0.000000,0.000000,-1.000000,0.000000,
      0.000000,-1.000000,0.000000,0.707107,-0.707107,0.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,
      0.000000,0.000000,1.000000,0.000000,0.000000,1.000000
    ];
  
    var arrow_indices =
    [
      0, 1, 2,      3, 4, 5,
      6, 7, 8,      9,10,11,  
      12, 13, 14,   15, 16, 17, 
      18, 19, 20,   21, 22, 23,
      24, 25, 26,   26, 27, 24,
      28, 29, 30,   30, 31, 28,
      32, 33, 34,   34, 35, 32,
      36, 37, 38,   38, 39, 36,
      40, 41, 42,   42, 43, 40,
      44, 45, 46,   46, 47, 44,
      48, 49, 50,   50, 51, 48,
      52, 53, 54,   54, 55, 52,
      56, 57, 58,   58, 59, 56,
      60, 61, 62,   62, 63, 60,
      64, 65, 66,   66, 67, 64,
      68, 69, 70,   70, 71, 68,
      72, 73, 74,   74, 75, 72,
      76, 77, 78,   78, 79, 76,
      80, 81, 82,   82, 83, 80,
      84, 85, 86,   86, 87, 84,
    ];
  
    this.vertices = arrow_vertices;
    this.indices  = arrow_indices;


  	this.meshArrow = new SglMeshGL(this.gl);
  	this.meshArrow.addVertexAttribute("position", 3, new Float32Array(arrow_vertices));
  	this.meshArrow.addVertexAttribute("normal",   3, new Float32Array(arrow_normals));
  	this.meshArrow.addArrayPrimitives("vertices", 	  this.gl.POINTS, 0, 88);
  	this.meshArrow.addIndexedPrimitives("triangles", this.gl.TRIANGLES, new Uint16Array(arrow_indices));
  
    this.updateBoundingBox(arrow_vertices);
  	  
    var async = (callback) ? (true) : (false);
    if (async) {
      callback(this);
    }
  },

  draw: function (gl, xform)
  {
    var color = [this.color[0] * this.highlightPass, this.color[1] * this.highlightPass , this.color[2] * this.highlightPass];

    var uniforms = { u_mvp : xform.modelViewProjectionMatrix , u_view_normal_mat : xform.viewSpaceNormalMatrix, u_color : color};
    sglRenderMeshGLPrimitives(this.meshArrow, "triangles", this.prog, null, uniforms);  
  },
});
