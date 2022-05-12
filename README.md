# Seam-Carving

Seam Carving is a technique for content-aware image resizing. Traditional resizing techniques such as cropping or uniform resizing do not preserve the aspect ratio of the important parts of the image. Seam carving is able to recognize important parts of an image and preserve those while resizing the image.

Seam carving does image resizing via deleting and/or inserting seams. A seam is a continuous path of pixels from top to bottom or left to right of an image.

In order to do so, we assign each pixel an 'energy' value depending on how 'important' it is. The energy value of a pixel is calculated by adding the differences in color between the neighboring pixels. Thus, pixels where the colors change drastically have higher energy. The energy of a seam is the sum of the energy of the pixels of the seam. Therefore, seams with lower energy will tend to avoid boundaries of important objects in the image, and thus avoid the objects altogether.

If we want to specifically avoid or remove cells, we can forcibly change their energy. For example, if we want to remove a certain pixel, we will assign a very low energy to it so that seams are more likely to go through that pixel. Similarly, if we want to keep a pixel, we assign a very high energy to it so that seams do not go through that pixel. One such case is faces. We do not want to edit the faces, so we use **facial recognition** to assign very high energy to faces. Similarly, when enlarging an image, we don't want to add the same seam over and over again. So, when we add a seam, we assign high energy to it, so that it doesn't get chosen again.

Seams with low energy is found using **Dijkstra's algorithm**, since this is essentially a shortest path problem.

This project is developed using OpenCV(version 4.5.0) and Qt(version 5.15.1 msvc 2019). We used Microsoft Visual Studio 2019 with the extension Qt VS Tools(version 2.6.0) to build the program.
