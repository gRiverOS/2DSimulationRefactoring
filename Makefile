all: bioluminiscencia

bioluminiscencia: main.o Writer.o  Point2D.o Point3D.o PointFactory.o Particle.o Geometry.o Box.o Rectangle.o Circumference.o MaterialProperties.o Material.o Body.o GeometryAlgorithms.o BodyContainerNode.o Random.o BodyContainer.o Step.o CustomBodyHandler.o ParticleChange.o PhotonParticleChange.o AbsorptionProcess.o ScatteringProcess.o PhotonProcessHandler.o Event.o Source.o SourceHandler.o EventFactory.o InputHandler.o Track.o Writer.o TrackingHandler.o EventDispatcher.o EventBuffer.o TimeHandler.o 
	u++ -Wall -multi -nodebug -O2 main.o Writer.o Point2D.o Point3D.o PointFactory.o Particle.o Geometry.o Box.o Rectangle.o Circumference.o MaterialProperties.o Material.o Body.o GeometryAlgorithms.o BodyContainerNode.o Random.o BodyContainer.o Step.o CustomBodyHandler.o ParticleChange.o PhotonParticleChange.o AbsorptionProcess.o ScatteringProcess.o PhotonProcessHandler.o Event.o Source.o SourceHandler.o EventFactory.o InputHandler.o Track.o Writer.o TrackingHandler.o EventDispatcher.o  EventBuffer.o TimeHandler.o  -o bioluminiscencia

main.o: main.cc
	u++ -Wall -multi -nodebug -c -O2 main.cc

	
TimeHandler.o: tracking/TimeHandler.cc
	u++ -Wall -multi -nodebug -c -O2 tracking/TimeHandler.cc

EventBuffer.o: tracking/EventBuffer.cc
	u++ -Wall -multi -nodebug -c -O2 tracking/EventBuffer.cc

TrackingHandler.o: tracking/TrackingHandler.cc
	u++ -Wall -multi -nodebug -c -O2 tracking/TrackingHandler.cc
	
EventDispatcher.o: tracking/EventDispatcher.cc
	u++ -Wall -multi -nodebug -c -O2 tracking/EventDispatcher.cc
	
Writer.o: io/Writer.cc
	u++ -Wall -multi -nodebug -c -O2 io/Writer.cc	

	
Track.o: tracking/Track.cc
	u++ -Wall -multi -nodebug  -c -O2 tracking/Track.cc
	
InputHandler.o: io/InputHandler.cc
	u++ -Wall -multi -nodebug -c -O2 io/InputHandler.cc
	
EventFactory.o: event/EventFactory.cc
	u++ -Wall -multi -nodebug -c -O2 event/EventFactory.cc
	
SourceHandler.o: event/SourceHandler.cc
	u++ -Wall -multi -nodebug -c -O2 event/SourceHandler.cc
	
Source.o: event/Source.cc
	u++ -Wall -multi -nodebug -c -O2 event/Source.cc
	
Event.o: event/Event.cc
	u++ -Wall -multi -nodebug -c -O2 event/Event.cc
	
PhotonProcessHandler.o: particle/PhotonProcessHandler.cc
	u++ -Wall -multi -nodebug  -c -O2 particle/PhotonProcessHandler.cc

ScatteringProcess.o: particle/ScatteringProcess.cc
	u++ -Wall -multi -nodebug  -c -O2 particle/ScatteringProcess.cc

AbsorptionProcess.o: particle/AbsorptionProcess.cc
	u++ -Wall -multi -nodebug  -c -O2 particle/AbsorptionProcess.cc

PhotonParticleChange.o: particle/PhotonParticleChange.cc
	u++ -Wall -multi -nodebug  -c -O2 particle/PhotonParticleChange.cc

ParticleChange.o: particle/ParticleChange.cc
	u++ -Wall -multi -nodebug -c -O2 particle/ParticleChange.cc

CustomBodyHandler.o:body/CustomBodyHandler.cc
	u++ -Wall -multi -nodebug  -c -O2 body/CustomBodyHandler.cc

Step.o: tracking/Step.cc
	u++ -Wall -multi -nodebug  -c -O2 tracking/Step.cc

BodyContainer.o: body/BodyContainer.cc
	u++ -Wall -multi -nodebug  -c -O2 body/BodyContainer.cc

Random.o: utils/Random.cc
	u++ -Wall -multi -nodebug  -c -O2 utils/Random.cc

BodyContainerNode.o: utils/BodyContainerNode.cc
	u++ -Wall -multi -nodebug  -c -O2 utils/BodyContainerNode.cc

GeometryAlgorithms.o: utils/GeometryAlgorithms.cc
	u++ -Wall -multi -nodebug  -c -O2 utils/GeometryAlgorithms.cc

Body.o: body/Body.cc
	u++ -Wall -multi -nodebug -c -O2 body/Body.cc
	
Material.o: body/Material.cc
	u++ -Wall -multi -nodebug -c -O2 body/Material.cc

MaterialProperties.o: body/MaterialProperties.cc
	u++ -Wall -multi -nodebug -c -O2 body/MaterialProperties.cc

Circumference.o: body/figure/Circumference.cc
	u++ -Wall -multi -nodebug -c -O2 body/figure/Circumference.cc	

Rectangle.o: body/figure/Rectangle.cc
	u++ -Wall -multi -nodebug -c -O2 body/figure/Rectangle.cc	

Box.o: body/figure/Box.cc
	u++ -Wall -multi -nodebug -c -O2 body/figure/Box.cc	

Geometry.o: body/Geometry.cc
	u++ -Wall -multi -nodebug  -c -O2 body/Geometry.cc	

Particle.o: particle/Particle.cc
	u++ -Wall -multi -nodebug  -c -O2 particle/Particle.cc

Point2D.o: common/Point2D.cc 
	u++ -Wall -multi -nodebug -c -O2 common/Point2D.cc

Point3D.o: common/Point3D.cc 
	u++ -Wall -multi -nodebug -c -O2 common/Point3D.cc

PointFactory.o: common/PointFactory.cc 
	u++ -Wall -multi -nodebug -c -O2 common/PointFactory.cc

clean:
	@ rm *.o; rm bioluminiscencia;