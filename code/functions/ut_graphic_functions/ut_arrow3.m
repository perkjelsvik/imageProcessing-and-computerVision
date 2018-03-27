function h = ut_arrow3(hg,a,b,linewidth,linecol,arrowlength,arrowwidth,arrowcol,Narrows,surfP)
% h = UT_ARROW3(hg,a,b,linewidth,linecol,arrowlength,arrowwidth,arrowcol,Narrows,surfP)
% draws a line between the 3D points a and b. Possibly Arrow(s) are included.
% linewidth, arrowwidth and arrowlength measure in the same unit as a and b.

switch nargin
    case 8
        Narrows = 0;
        surfP.dummy = 0;
    case 9
        surfP.dummy = 0;
    case 10
    otherwise
        error('ut_arrow3: inproper number of arguments');
end

if isempty(surfP), surfP.dummy=1; end
if Narrows==0, arrowwidth = linewidth; end

%determine the point where the arrows start:
Lfull = norm(a-b);
Lline = Lfull  - arrowlength*Narrows;
if Lline<=0
    error('ut_arrow3: arrowlength too large');
end
if Narrows>0
    bline = b - (b-a)*arrowlength/Lfull;
else
    bline = b;
end
if Narrows>1
    aline = a + (b-a)*arrowlength/Lfull;
else
    aline = a;
end

% draw the line
h = ut_cylinder2p([], linewidth, 50,aline,bline,linecol, surfP);

% draw the arrow:
if Narrows>0
    h = [h ut_cylinder2p([], [arrowwidth 0 ], 50, bline, b, arrowcol, surfP)];
    h = [h ut_disk2p([] ,arrowwidth, 50 ,bline, a, linecol, surfP)];
end
% draw the 2nd arrow if wanted:
if Narrows>1
    h = [h ut_cylinder2p([], [arrowwidth 0 ], 50, aline, a, arrowcol, surfP)];
    h = [h ut_disk2p([] ,arrowwidth, 50 ,aline, b, linecol, surfP)];
end

if ~isempty(hg)
    for n=1:length(h)
        set(h(n),'Parent',hg);
    end
end

end








