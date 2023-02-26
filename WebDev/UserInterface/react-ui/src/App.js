import logo from './logo.svg';
import './App.css';

function App() {
  return(
    <Desktop1 run = "RUN" aboutWireFrame='about-wire-frame.png'
    mapping='Mapping:' dataFooter='data-footer.png'
    />
  )
}


function Desktop1(props) {
  const {run, aboutWireFrame, mapping, dataFooter } = props
  return(
    <div className='container-center-horizontal'>
      <div className='desktop-1 screen'>
        <div className='overlap-group'>
          <div className='frame-1988'>
            <div className='frame-1990'>
              <div className='run'>
                (run)
              </div>
              <img className='codiconrun-all' src='codicon-run-all.svg'
              alt='codicon:run-all' />
            </div>
            <img className='about-wire-frame' src={aboutWireFrame}
            alt='About Wire Frame' />
          </div>
          <div className='mapping-wire-frame'>
            <div className='mapping'>
              (mapping)
            </div>
          </div>
          <img className='data-footer' src={dataFooter} alt='Data Footer' />
        </div>
      </div>
    </div>
  );
}

export default App;
