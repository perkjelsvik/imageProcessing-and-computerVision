function h = ut_plot_axis3D(varargin)
%UT_PLOT_AXIS3D plot the 3D axes defined by transform T
%   h = ut_plot_axis3D(hg, T, [options]) plots the axes of a 3D coordinate
%   system defined by the homogeneous transform matrix T.
%   Options are: 'arrowlength','length','l','arrowcolor','color','col','orglabel','axlabels','surfparm'};
%   'arrowlength', 'length', or 'l':        the length of the arrows
%   'arrowcolor', color', or 'col':         the color of the arrows
%   'orglabel':                             a possible textlabel placed near the origin
%   'axlabels':                             if given, the axis textlabels are shown
%   'surfparm':                             surf properties
%
%   The lenght of arrow is a single number (default: 1)
%   The color of the arrow is a 1x3 array (default: [0.2 0.2 0.2]
%   The orglabels must be a string (default: empty)
%   The axes labels is without argument (default false)
%   The surfparm gives the radiometric properties of the arrow defined by a
%   struct. All struct fields must be a surf property name, denoted in
%   lower case. E.g. surfparm.facecolor. These fields overwrite their defaults
%   (see m-code). 
%
%   The function returns the handle to the patch object.
%
%	If hg is empty, this argument is ignored.
%	If hg is not empty, it must be the handle of a hgtransform object.
%	In that case, the surface is parented to hg. This is particularly useful
%	for constructing more complex graphical objects which can be transformed
%	with the properties of a hgtransform object.
%
%   CHANGED 19/06/2015 FvdH:    The columns of the rotation matrix are
%                               selected instead of the rows.

[hg,T,surfparm,linelength,arrowcol,orglabel,axlabels]=ParseInputs(varargin{:});
linewidth = 0.03*linelength;
arrowlength = 0.17*linelength;
arrowwidth = 0.10*linelength;


a = T(1:3,4);
% b = a + linelength*T(1,1:3)'; % changed: 19/06/2015
b = a + linelength*T(1:3,1);
h = ut_arrow3([],a',b',linewidth,arrowcol,arrowlength,arrowwidth,arrowcol,1,surfparm);
% b = a + linelength*T(2,1:3)'; % changed: 19/06/2015
b = a + linelength*T(1:3,2);
h = [h ut_arrow3([],a',b',linewidth,arrowcol,arrowlength,arrowwidth,arrowcol,1,surfparm)];
% b = a + linelength*T(3,1:3)'; % changed: 19/06/2015
b = a + linelength*T(1:3,3);
h = [h ut_arrow3([],a',b',linewidth,arrowcol,arrowlength,arrowwidth,arrowcol,1,surfparm)];
if axlabels
    h  = [h text(a(1)+linelength*T(1,1)',a(2)+linelength*T(2,1)',a(3)+linelength*T(3,1)','x')];
    h  = [h text(a(1)+linelength*T(1,2)',a(2)+linelength*T(2,2)',a(3)+linelength*T(3,2)','y')];
    h  = [h text(a(1)+linelength*T(1,3)',a(2)+linelength*T(2,3)',a(3)+linelength*T(3,3)','z')];
end
h = [h text(a(1),a(2),a(3),orglabel)];

if ~isempty(hg)
    set(h,'Parent',hg);
end
end






%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [hg,T,surfparm,arrowlength,arrowcol,orglabel,axlabels] =  ParseInputs(varargin)

narginchk(1,30);


hg = varargin{1};
T =  varargin{2};
if ~ismatrix(T) || size(T,1)~=4 || size(T,2)~=4
    error('T  must be a 4x4 homogeneous transformation matrix');
end
surfparm.dummy = 0;

%defaults
arrowlength = 1;
arrowcol = [0.2 0.2 0.2];
orglabel = '';
axlabels = false;

options = {'arrowlength','length','l','arrowcolor','color','col','orglabel','axlabels','surfparm'};

if nargin>2
    for k=3:length(varargin)
        if ischar(varargin{k})
            string = lower(varargin{k});
            ind = strcmp(string,options);
            j = find(ind, 1);
%             if isempty(j)
%                 error(['Invalid input string: ''' varargin{k} '''.']);
%             end
            switch string
                case {'arrowlength','length','l'}
                    if nargin>k && isnumeric(varargin{k+1})
                        arrowlength = varargin{k+1};
%                         k = k+2;
                    end
                case {'arrowcolor','color','col'}
                    if nargin>k && isnumeric(varargin{k+1})
                        arrowcol = varargin{k+1};
                        if length(arrowcol)~=3, error('invalid color'); end
%                         k=k+2;
                    end
                case {'orglabel'}
                    if nargin>k
                        orglabel = varargin{k+1};
%                         k=k+2;
                    end
                case {'surfparm'}
                    if nargin>k
                        surfparm = varargin{k+1};
%                         k=k+2;
                    end
                case {'axlabels'}
                    axlabels = true;
            end
        end
    end
end
end

