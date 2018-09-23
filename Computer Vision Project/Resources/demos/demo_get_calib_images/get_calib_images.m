%% get a sequence of images from a camera for camera calibration

%% clean up
if exist('vid')
    delete(vid);
    clear vid
end
clc
close all

%% preamble
imaqhwinfo  % Which adaptor is available?
            % adaptor = software that communicates 
            % to the device driver of the camera
info = imaqhwinfo('winvideo')   % get info of an adaptor
info = imaqhwinfo('winvideo',1) % get info a the device associated with the adaptor
info.SupportedFormats           % the supported formats

%% create a video object
vid = videoinput('winvideo',1,'YUY2_1280x720'); %  construct the video input object 
preview(vid);                                   % Test camera using preview
uiwait(helpdlg('press to continu'));            % wait until the button is pressed
closepreview(vid);                              % close the preview
vidsize = vid.VideoResolution;                  % image size
    
%% Configure the object for manual trigger mode.
% triggerconfig(vid, 'manual');
% % Now that the device is configured for manual triggering, call START.
% % This will cause the device to send data back to MATLAB, but will not log
% % frames to memory at this point.
% start(vid)

im = getsnapshot(vid);                          % image data acquisition
imshow(im);                                     % set whether the colorspace is correct
vid.ReturnedColorSpace='rgb';                   % set the color space to rgb

%% read data from the camera
n = 12;                                         % set the number of images to acquire
fname = 'foo_';                                 % set the filename
i = 1;
while i <= n
    preview(vid);                               % preview until the image looks fine
    uiwait(helpdlg('press to continu'));
    closepreview(vid);
    
    im = getsnapshot(vid);                      % image data acquisition
    
    figure(1), imshow(im); title(num2str(i));   % inspect
    button = questdlg('image OK?');
    if strcmp(button,'Yes')             
        savename = [fname,num2str(i), '.tif'];  % save if ok
        imwrite(im, savename);
        i = i+1;
    elseif strcmp(button,'Cancel')              % abort the procedure
        break;
    end                                         % otherwise: do it again
end

close all
% stop(vid);
delete(vid);
