%% ex1 - camera models
close all
clear variables

%% define output video
outputname = 'optic_flow_car_clip';
profile = 'MPEG-4';
framerate = 5;
quality = 100;

wobj = VideoWriter(outputname,profile);
wobj.FrameRate = framerate;
wobj.Quality = quality;
open(wobj);


% %% read data
fname = 'car_clip4.avi';
vidReader = VideoReader(fname);


% opticFlow1 = opticalFlowHS('MaxIteration',10,'Smoothness', 0.1);
% opticFlow1 = opticalFlowLKDoG('GradientFilterSigma',1,...
%     'NumFrames',9,'ImageFilterSigma',1.5,'NoiseThreshold',0.0001); %0.004);
opticFlow = opticalFlowFarneback;



while hasFrame(vidReader)
    frameRGB = readFrame(vidReader);
    frameGray = rgb2gray(frameRGB);
    flow = estimateFlow(opticFlow,frameGray);
    
    imshow(frameRGB)
    hold on
    h=plot(flow,'DecimationFactor',[20 20],'ScaleFactor',4);
    hh = get(h,'children');
    set(hh(1),'color','r');
    hold off
    drawnow
    Iout = getframe;
    writeVideo(wobj,Iout.cdata);
%     iskip = 1;
%     while hasFrame(vidReader)
%         frameRGB = readFrame(vidReader);
%         iskip = iskip+1;
%         if iskip>4, break; end
%     end

end
close(wobj)




