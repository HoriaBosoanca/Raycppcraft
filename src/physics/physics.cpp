#include "btBulletDynamicsCommon.h"
#include "raylib.h"

namespace Physics
{
    btDiscreteDynamicsWorld* dynamicsWorld;
    btAlignedObjectArray<btCollisionShape*> collisionShapes;
    btRigidBody* playerRb;

    void init() {
        btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
        btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
        btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
        btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
        dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
        dynamicsWorld->setGravity(btVector3(0.0f, -10.0f, 0.0f));
    }

    void update() {
        dynamicsWorld->stepSimulation(GetFrameTime());
    }

    void add_static_cube(float x, float y, float z) {
        btCollisionShape* cube = new btBoxShape(btVector3(0.5f, 0.5f, 0.5f));
        collisionShapes.push_back(cube);
        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(btVector3(x, y, z));
        btRigidBody::btRigidBodyConstructionInfo rbInfo(
            0.0f,
            new btDefaultMotionState(transform),
            cube,
            btVector3(0.0f, 0.0f, 0.0f)
        );
        dynamicsWorld->addRigidBody(new btRigidBody(rbInfo));
    }

    void init_player() {
        btCollisionShape* player = new btBoxShape(btVector3(0.5f, 1.0f, 0.5f));
        collisionShapes.push_back(player);
        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(btVector3(0.0f, 50.0f, 0.0f));
        float mass = 50.0f;
        btVector3 localInertia;
        player->calculateLocalInertia(mass, localInertia);
        btRigidBody::btRigidBodyConstructionInfo rbInfo(
            mass,
            new btDefaultMotionState(transform),
            player,
            localInertia
        );
        playerRb = new btRigidBody(rbInfo);
        playerRb->setAngularFactor(btVector3(0.0f, 0.0f, 0.0f));
        dynamicsWorld->addRigidBody(playerRb);
    }

    void add_force_player(float x, float y, float z) {
        playerRb->applyCentralForce(btVector3(x, y, z));
    }

    btVector3 get_player_pos() {
        return playerRb->getWorldTransform().getOrigin();
    }

    bool did_player_collide_any() {
        for (int i = 0; i < dynamicsWorld->getDispatcher()->getNumManifolds(); i++) {
            btPersistentManifold* manifold = dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
            const btCollisionObject* a = manifold->getBody0();
            const btCollisionObject* b = manifold->getBody1();
            if (manifold->getNumContacts() > 0 && (a == playerRb || b == playerRb)) {
                return true;
            }
        }
        return false;
    }
}