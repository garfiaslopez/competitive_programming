const baseUrl = "https://images.unsplash.com/";
const queryParams = "?auto=format&fit=crop&w=450&q=100";

const images = [
  { id: 0, url: "photo-1475700262322-d2d5adb9e26f", alt: "cute dog" },
  { id: 1, url: "photo-1459541708374-6fe9eea39a29", alt: "guinea pig" },
  { id: 2, url: "photo-1571198317078-76a4b545b2c1", alt: "night" },
  { id: 3, url: "photo-1553301139-3c610dd5b1cb", alt: "beach" }
];

const Image = ({ image, className, onClick }) => {
  const unsplashUrl = baseUrl + image.url + queryParams;
  const imageClass = className ? `image ${className}` : "image";
  const style = { backgroundImage: `url(${unsplashUrl})` };

  return (
    <div
      role="img"
      aria-label={image.alt}
      style={style}
      className={imageClass}
      onClick={() => onClick(image.id)}
    />
  );
};

const Thumbnails = ({ active, onClick, images }) => {
  return (
    <div className="thumbnails">
      {images.map(image => {
        let className = "thumbnail";
        if (image.id === active) {
          className += " thumbnail--active";
        }
        return (
          <Image
            image={image}
            key={image.id}
            className={className}
            onClick={onClick}
          />
        );
      })}
    </div>
  );
};

const Button = ({ children, onClick }) => {
  return (
    <button className="button" onClick={onClick}>
      {children}
    </button>
  );
};

const ImageGallery = () => {
  return (
    <div className="app">
      <small>
        images taken from <a href="https://unsplash.com/">Unsplash</a>
      </small>
      <div className="front-image">
        <Image image={images[0]} />
      </div>
      <Thumbnails active={images[0].id} images={images} />
      <div className="actions">
        <Button>Prev</Button>
        <Button>Play</Button>
        <Button>Next</Button>
      </div>
    </div>
  );
};

ReactDOM.render(
  <ImageGallery />,
  document.getElementById('app')
);

