ffmpeg -i input_video.mp4 -ss 00:00:30 -t 00:00:10 -c:a copy -c:v copy cropped.mp4;
convert -resize 50% -depth 8 -background none plate.svg plate.png;
ffmpeg -i cropped.mp4 -i plate.png -filter_complex "overlay=enable='between(t,1,9)':x=0:y=446" -c:a copy plated.mp4;
ffmpeg -i plated.mp4 -vf drawtext="text='hello':fontfile=Arial.ttf:fontcolor=black:fontsize=24:x=200:y=476:enable='between(t,2,9)'" -c:a copy result.mp4;