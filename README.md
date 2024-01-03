This is an extended version of *KidBasic* code-named **KidBasic++**.

The main motivation is to add *statements* and *functions* that are crucial for **game development** within the *KidBasic* language.

Its basis is a fork from the *SVN revision 667*. You'll find the current state of the vanilla project [here](https://sourceforge.net/p/kidbasic/code/HEAD/tree/).

Note that the compiled interpreter is still called `BASIC256` for compatibility for existing scripts and start configurations.

# Additions to Vanilla KidBasic

* `ABORT`
    * aborts BASIC256 immediately

* `ARGS`
    * returns the arguments that were passed to BASIC256 from the command line with option -a

* `BREAKPOINT`
    * forces the debugger to stop at this statement, user can choose debug/step afterwards

* `CLIPPINGRECT x , y , width , height`
    * Sets the rectangle within the graph window into which graphical operations are able to paint to

* `CLIPPINGRESET`
    * Resets the clipping to its default setting (clipping region is the complete graphsize)

* `FONTASCENT`
    * returns the ascent of the the current font

* `FONTDESCENT`
    * returns the descent of the the current font

* `IMGHEIGHT Image-FileName`
    * returns the height of the image file (0 if not found)
* `IMGWIDTH Image-FileName`
    * returns the width of the image file (0 if not found)

* `RECTIMG pseudo file name , x , y , width , height`
    * Puts the region as a new image into the image buffer and assigns it to a pseudo file name.
    * Subsequent imgload, imgwidth, imgheight can refer to this image by using that file name.

* `WAVPLAY [ channel , ] Wav-FileName [ , loop-number ]`
    * loop-number has to be given if channel is given
    * loop-number -1 means infinite loop
    * loop-number 0 means only one playthrough
    * defaults: channel = 0 , loop-number = 0
    * Note that files are buffered, subsequent plays do not re-access the file system

* `WAVSTOP [(] [ channel ] [)]`
    * defaults: channel = 0

* `WAVWAIT [(] [ channel ] [)]`
    * defaults: channel = 0
