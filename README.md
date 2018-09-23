# [191210910 - Image Processing and Computer Vision](https://osiris.utwente.nl/student/OnderwijsCatalogusSelect.do?selectie=cursus&taal=en&collegejaar=2017&cursus=191210910)
A course on Image Processing and Computer Vision I took at University of Twente as an exchange student spring 2018. The course featured three Image Processing exercises that were individual, and a larger Computer Vision project done in pairs of two or alone. I worked with another person for my project. 

## Course Content
The course familiarizes students with digital image processing and computer vision techniques. It provides the fundaments for 2-D signal processing applied to digital images. It also discusses techniques for the extraction of 2D, 3D, or 4D information that is represented by a digital image (or image sequence). Examples of computer vision tasks are:

- The detection, e.g. checking the presence of an object or event.
- The recognition or identification of an object or person.
- The measurement of the parameters of an object, e.g. position, size, shape.
- Motion analysis of objects.

The topics of the course include image formation and acquisition, 2D Fourier transforms, image operations, image segmentation, regional description, recognition and parameter estimation. The course involves practical work in which the students design a vision system for a simple application. As such, the student acquires programming skills using Matlab and its image processing toolbox. Examples of design tasks that students can select are:

- Virtual advertising:inserting virtual advertising images into recorded movies of sports events  
- Motion analysis: tracking an object in a cluttered movie.
- 3D face reconstruction from 3 images
- 3D tracking of facial point features.

## Image Processing Exercises
### Exercise 1 - Basics of convolution and Fourier transform
A more theoretical exercise where we had to analyze data in a given picture with noise/distortions. The picture has several horizontal lines across it that's not wanted. The task was to read data from the picture in the frequency plane, and then filter the picture in a way that minimized the effect of the distortion, while keeping the original information of the picture. 

### Exercise 2 - Image registration and geometrical transforms
This exercise was perhaps the most demanding in terms of hours of coding work to achieve desirable results. The main objective was to stitch together 4 different images of a map to a complete image. The requirements were to have as few mismatches as possible between lines, as well as achieving correct distance relations of the map. Part of the challenge is that the original images are taken from different perspectives, so you have to find a way to stretch the images so that they match each other (projective transformation). While there are several techniques to stitch images together, we were tasked to do it sequentially for this exercise, with the top right image as the starting point. 

### Exercise 3 - Measurements of the diameter of arteries in angiograms
This exercise was a good mix of practical application and theory. The exercise was to use an X-Ray image of arteries to find information about for example the diameter of the arteries, which is used extensively in different medical applications. In the exercise, we were tasked to use several different methods, but the objective and goal was the same: get the information in the best possible way.

## Computer Vision Project - 3D face reconstruction
In the course we also had a large project as mentioned. Unfortunately, me and my collaborator didn't have sufficient time available to achieve great results. Therefore we ended up with not completing the final part of the task, and parts of the things we did achieve were not as reliable as we would have liked. Still, the results are not bad, and the project served its purpose of learning several new things.

In more detail, our assignment was to design a method for creation of 3D surface meshes of the faces of subjects. Three subjects are imaged from three different points of view, and with five different facial expressions. Two sets of calibration images were also given. So we had to find intrinsic and external parameters of the camera, compensate for non-linear lens deformation, stereo rectify (to achieve dense stereo matching), global color normalization ("constant brightness assumption"), disparity map (depth map estimation), background detection (remove background), mapping unreliable disparities so that they can be removed from the mesh, and finally merging two 3D surface meshes to one mesh (ICP algorithm). In addition, a rough assessment of the quality of the mesh, determining a way to quantify quality. 

We were able to mostly everything required for the project, except the final merging of two 3D surface meshes. Again, not with the best of results, but all things considered I think it's not too bad, especially in the short time frame we had available. An interesting project nevertheless. 
